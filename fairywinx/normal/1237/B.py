n = int(input())
a = [0] * n
b = [0] * n
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = [0] * n
for i in range(n):
    c[a[i] - 1] = i
mn = c[b[n - 1] - 1]
ans = 0
for i in range(n - 2, -1, -1):
    #print(b[i], c[b[i] - 1], mn)
    if c[b[i] - 1] > mn:
       #print(b[i])
        ans += 1
    mn = min(mn, c[b[i] - 1])
    
print(ans)