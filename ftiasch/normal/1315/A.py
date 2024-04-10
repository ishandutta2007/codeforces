for _ in range(int(input())):
  a, b, x, y = map(int, input().split())
  print(max(max(x, a - 1 - x) * b, max(y, b - 1 - y) * a))