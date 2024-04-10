n, m = map(int, input().split())
mx = 0
a = [int(i) for i in input().split()]
a = [i for i in a if i < 0]
if not a:
  print(mx)
  exit(0)
m = min(m, len(a))
a.sort()
print(sum(abs(i) for i in a[:m]))