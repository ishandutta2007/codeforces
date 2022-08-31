n = int(input())
a = list(map(int, input().split()))
good = True
while a:
  if any(abs(x-y) >= 2 for x,y in zip(a, a[1:])): good = False
  a.remove(max(a))
print("YES" if good else "NO")