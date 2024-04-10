n = int(input())
a = [int(i) for i in input().split()]
mn = min(a)
a = [i for i, val in enumerate(a) if val == mn]
mn = float("inf")
for i in range(len(a) - 1):
  mn = min(mn, a[i + 1] - a[i])
print(mn)