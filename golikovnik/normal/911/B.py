n, a, b = map(int, input().split())
mx = -1
for x in range(1, min(a, b) + 1):
  if a // x + b // x >= n:
    mx = max(mx, x)
print(mx)