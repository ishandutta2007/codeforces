n, k = map(int, input().split())
a = list(map(int, input().split()))

check = True
for i in range(1, n):
    check = check and (a[i] % k == a[0] % k)
    
if not check:
    print(-1)
else:
    m = min(a)
    ans = 0
    for i in range(n):
        ans += a[i] - m
        
    print(ans // k)