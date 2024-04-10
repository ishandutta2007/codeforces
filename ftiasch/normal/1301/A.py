for _ in range(int(input())):
  a = input()
  b = input()
  c = input()
  print("YES" if all(x == z or y == z for x, y, z in zip(a, b, c)) else "NO")