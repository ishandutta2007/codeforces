n, m = map(int, input().split())
a = [0] * n
p = [0] * m
ans = 10 ** 6
for i in range(m):
    l, r = map(int, input().split())
    ans = min(ans, r - l + 1)

k = 0
for i in range(n):
    a[i] = k
    k = (k + 1) % ans
      
print(ans)
print(' '.join(map(str, a)))