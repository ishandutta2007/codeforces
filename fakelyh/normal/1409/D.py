for _ in range(int(input())):
    n, s = map(int, input().split())
    t = n
    sm = 0
    q = 1
    while t:
        sm += t % 10
        t //= 10
    ans = 0
    while sm > s:
        ans+=q*(10-n%10)
        n+=10-n%10
        sm=0
        while n%10==0:
            n//=10
            q*=10
        t=n
        while t:
            sm+=t%10
            t//=10
        # print(n,q)
    print(ans)