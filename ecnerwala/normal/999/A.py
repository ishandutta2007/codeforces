n,k = map(int, input().split())
a = [*map(int, input().split())]
res = 0
for _ in range(2):
  while a and a[-1] <= k:
    a.pop()
    res += 1
  a = a[::-1]
print(res)