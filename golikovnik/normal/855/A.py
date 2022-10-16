used = set()
n = int(input())
for _ in range(n):
  s = input()
  print("YES" if s in used else "NO")
  used.add(s)