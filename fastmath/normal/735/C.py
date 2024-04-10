def cost(nk):
    
    ns = max(0, k - 1)
    if ns > n - 2:
        return 0
    
    return f(n - ns - 1, k + 1) + 1


n = int(input())
F = [0] * 100
F[0] = 1
F[1] = 2
ans = 1

for i in range(2, 100):
    F[i] = F[i - 1] + F[i - 2]
    if F[i] <= n:
        ans = i
        
print(ans)