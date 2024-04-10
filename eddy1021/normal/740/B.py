n, m = map(int, input().split())
a = list(map(int, input().split()))
for i in range(1,len(a)): a[i] += a[i-1]
ans = 0
for i in range(0, m):
  l, r = map(int, input().split())
  ans += max(0, a[r-1] - (0 if l == 1 else a[l-2]))
print(ans)