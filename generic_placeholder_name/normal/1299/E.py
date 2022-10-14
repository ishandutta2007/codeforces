def ask(a):
    if len(a) == 1:
        return True
    print('?', len(a), *a)
    return input() != '0'

def main(): 
    n = int(input())
    a = [None] * (n + 1)
    is_odd = [False] * (n + 1)
    pos = [None] * (n + 1)
    
    #find 1 and n
    one_yet = False
    for i in range(1, n + 1):
        arr = list(range(1, i)) + list(range(i + 1, n + 1))
        if ask(arr):
            if not one_yet:
                a[i] = 1
                pos[1] = i
                one_yet = True
            else:
                a[i] = n
                pos[n] = i
    
    #parity check
    for i in range(1, n + 1):
        if a[i] != None:
            is_odd[i] = (a[i] & 1) == 1
        else:
            is_odd[i] = ask([pos[1], i])
    
    #find from 2 
    for m in range(2, min(5, n // 2 + 1)):
        for i in range(1, n + 1):
            if a[i] == None:
                arr = []
                for j in range(1, n + 1):
                    if (a[j] == None or a[j] == m or a[j] == n + 1 - m) and j != i:
                        arr.append(j)
                if ask(arr):
                    if is_odd[i] == ((m & 1) == 1):
                        a[i] = m
                        pos[m] = i
                    else:
                        a[i] = n + 1 - m
                        pos[n + 1 - m] = i
    
    #find remainders mod 3 5 7 8
    if n > 8:
        #modulo 3
        mod_3_arr = [[pos[1], pos[2]], [pos[1], pos[3]], [pos[2], pos[3]]]
        a_mod_3 = [None] * (n + 1)
        for i in range(1, n + 1):
            if a[i] == None:
                if ask(mod_3_arr[0] + [i]):
                    a_mod_3[i] = 0
                elif ask(mod_3_arr[2] + [i]):
                    a_mod_3[i] = 1
                else:
                    a_mod_3[i] = 2
        
        #modulo 5
        mod_5_arr = [None] * 5
        a_mod_5 = [None] * (n + 1)
        for i in (1, 2, 3, 4):
            mod_5_arr[(3 * n - 3 + i) % 5] = [pos[i], pos[n], pos[n - 1], pos[n - 2]]
        mod_5_arr[(3 * n - 3) % 5] = [pos[n], pos[n - 1], pos[n - 3], pos[1]]
        for i in range(1, n + 1):
            if a[i] == None:
                for j in range(0, 5):
                    if j == 4 or ask(mod_5_arr[(5 - j) % 5] + [i]):
                        a_mod_5[i] = j
                        break
        
        #modulo 7
        mod_7_arr = [None] * 7
        a_mod_7 = [None] * (n + 1)
        for arr in ([n, n - 1, n - 2], [n, n - 1, n - 3], [n, n - 2, n - 3], [n - 1, n - 2, n - 3]):
            mod_7_arr[(sum(arr) + 6) % 7] = [pos[i] for i in arr] + [pos[1], pos[2], pos[3]]
        for arr in ([1, 2, 4], [1, 3, 4], [2, 3, 4]):
            mod_7_arr[(sum(arr) + 3 * n - 3) % 7] = [pos[i] for i in arr] + [pos[n], pos[n - 1], pos[n - 2]]
        for i in range(1, n + 1):
            if a[i] == None:
                for j in range(0, 7):
                    if j == 6 or ask(mod_7_arr[(7 - j) % 7] + [i]):
                        a_mod_7[i] = j
                        break
        
        #modulo 4
        mod_4_arr = [[pos[1], pos[3], pos[4]], [pos[2], pos[3], pos[4]]]
        a_mod_4 = [None] * (n + 1)
        for i in range(1, n + 1):
            if a[i] == None:
                if is_odd[i]:
                    if ask(mod_4_arr[1] + [i]):
                        a_mod_4[i] = 3
                    else:
                        a_mod_4[i] = 1
                else:
                    if ask(mod_4_arr[0] + [i]):
                        a_mod_4[i] = 0
                    else:
                        a_mod_4[i] = 2
        
        #modulo 8
        mod_8_arr = [
                [pos[n], pos[n - 1], pos[n - 2], pos[n - 3], pos[1], pos[2], pos[3]],
                [pos[n], pos[n - 1], pos[n - 2], pos[n - 3], pos[1], pos[2], pos[4]],
                [pos[n], pos[n - 1], pos[n - 2], pos[n - 3], pos[1], pos[3], pos[4]],
                [pos[n], pos[n - 1], pos[n - 2], pos[n - 3], pos[2], pos[3], pos[4]]
                ]
        a_mod_8 = [None] * (n + 1)
        for i in range(1, n + 1):
            if a[i] == None:
                if a_mod_4[i] == 0:
                    if ask(mod_8_arr[0] + [i]):
                        a_mod_8[i] = 0
                    else:
                        a_mod_8[i] = 4
                elif a_mod_4[i] == 1:
                    if ask(mod_8_arr[3] + [i]):
                        a_mod_8[i] = 5
                    else:
                        a_mod_8[i] = 1
                elif a_mod_4[i] == 2:
                    if ask(mod_8_arr[2] + [i]):
                        a_mod_8[i] = 6
                    else:
                        a_mod_8[i] = 2
                else:
                    if ask(mod_8_arr[1] + [i]):
                        a_mod_8[i] = 7
                    else:
                        a_mod_8[i] = 3
                        
        #fill in number
        def comb(mod_3, mod_5, mod_7, mod_8):
            for a in range(1, 841):
                if a % 3 == mod_3 and a % 5 == mod_5 and a % 7 == mod_7 and a % 8 == mod_8:
                    return a
            assert(False)
        
        for i in range(1, n + 1):
            if a[i] == None:
                a[i] = comb(a_mod_3[i], a_mod_5[i], a_mod_7[i], a_mod_8[i])
    
    #answer
    if a[1] > n // 2:
        for i in range(1, n + 1):
            a[i] = n + 1 - a[i]
    print('!', *a[1::])

main()