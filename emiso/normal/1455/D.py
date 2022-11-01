t = int(input())
for tt in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    
    if a == sorted(a):
        print(0)
    else:
        ans = 0
        cur = x
        for i in range(n):
            if a[i] > cur:
                a[i], cur = cur, a[i]
                ans += 1
                if a == sorted(a): break
        if a == sorted(a):
            print(ans)
        else:
            print(-1)