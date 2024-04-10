def f(n, p, k):
    n = n - k * p
    ans = 0
    l = 0
    z = []
    while (n >= 1):
        ans += (n % 2)
        z.append(n % 2)
        n //= 2
    #print(z)
    #print(ans, k)
    #z = z[::-1]
    for i in range(len(z)):
        l += z[i] * 2 ** i
    #print(l, ans)
    if ans <= k <= l:
        return ans
    else:
        return 10 ** 4
 
n, p = map(int, input().split())
k = 10000
ans = 10 ** 4
for i in range(1, 10 ** 4):
    if f(n, p, i) != 10 ** 4:
        print(i)
        exit(0)
print(-1)