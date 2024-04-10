t = int(input())
for u in range(t):
        n = int(input())
        s1 = input()
        s2 = input()
        a = dict()
        k = 0
        b = []
        for i in range(n):
                if s1[i] != s2[i]:
                        k += 1
                        b.append(i)
        if k > 2:
                print('NO')
        elif k == 1:
                print('NO')
        elif k == 0:
                print('YES')
        else:
                if s1[b[0]] == s1[b[1]] and s2[b[0]] == s2[b[1]]:
                        print('YES')
                else:
                        print('NO')