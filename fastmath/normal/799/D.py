def gen(o, gen1):
    if o == len(my_arr):
        fp = 1
        sp = 1
        
        for i in range(len(my_arr)):
            fp *= my_arr[i][0] ** gen1[i]
            sp *= my_arr[i][0] ** (my_arr[i][1] - gen1[i])
            
        if (h * fp >= a and w * sp >= b) or (h * fp >= b and w * sp >= a):
            return True
        
        return False
    
    for i in range(my_arr[o][1] + 1):
        if gen(o + 1, gen1 + [i]):
            return True
        
    return False


a, b, h, w, n = map(int, input().split())

arr = list(map(int, input().split()))
arr.sort(reverse = True)

arr2 = []
for i in range(n):
    if (not i) or arr[i] != arr[i - 1]:
        arr2.append([arr[i], 1])
    else:
        arr2[-1][1] += 1
    
    
if (h >= a and w >= b) or (h >= b and w >= a):
    print(0)
else:
    my_arr = []
    j = -1
    ans = -1
    for i in range(1, min(34, len(arr)) + 1):
        if my_arr and my_arr[-1] < arr2[j]:
            my_arr[-1][1] += 1
        else:
            j += 1
            my_arr.append([arr2[j][0], 1])
            
        if gen(0, []):
            ans = i
            break
        
    print(ans)