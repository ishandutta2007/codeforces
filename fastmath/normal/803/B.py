n = int(input())
a = list(map(int, input().split()))

inf = 10 ** 9
ans = [inf] * n
l = inf
for i in range(n):
    if not a[i]:
        l = 0
    
    ans[i] = min(ans[i], l)
    l += 1

l = inf
for i in range(n - 1, -1, -1):
    if not a[i]:
        l = 0
    
    ans[i] = min(ans[i], l)
    l += 1
    
print(' '.join(map(str, ans)))