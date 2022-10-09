n = int(input())

for i in range(n):
    q = int(input())
    ans = 0
    a = list(map(int, input().split()))
    mn = a[q - 1]
    for j in range(q - 1, -1, -1):
        #print(mn, a[j], a[j] > mn)
        if a[j] > mn:
           ans += 1
        mn = min(a[j], mn)
    print(ans)