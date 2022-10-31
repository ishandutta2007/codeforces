n, m = list(map(int,input().split()))
d = dict()
for i in range(m):
  a, b = input().split()
  d[a] = b if len(b) < len(a) else a
print(" ".join(d[i] for i in input().split()))