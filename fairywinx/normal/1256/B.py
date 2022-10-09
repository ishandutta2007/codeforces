
t = int(input())
for u in range(t):
    b = set()
    n = int(input())
    a = list(map(int, input().split()))
    kol = 0
    for i in range(n):
        if a[i] != i + 1:
            k_i = 0
            for j in range(n):
                if a[j] == i + 1:
                    k_i = j
                    break
 
            for j in range(k_i - 1, -1, -1):
                #print(a, k_i, i+ 1)
                if kol == n - 1:
                    break
                if (j, j + 1) not in b:
                    if a[j] > a[j + 1]:
                        a[j], a[j + 1] = a[j + 1], a[j]
                        b.add((j, j + 1))
                        kol += 1
                        if j == i:
                            break
                    else:
                        break
                else:
                    break
    print(*a)