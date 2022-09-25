for T in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    ans = 0
    for i in range(n):
        for j in range(a[i]-i-2,n,a[i]):
            ans += i+j+2==a[i]*a[j] and i<j
    print(ans)