k1, k2, k3 = sorted(map(int, input().split()))
if k1 == 1 or (k1, k2) == (2, 2) or (k1, k2, k3) in [(3, 3, 3), (2, 4, 4)]:
  print("YES")
else:
  print("NO")