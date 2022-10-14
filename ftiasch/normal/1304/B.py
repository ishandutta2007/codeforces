n, m = map(int, input().split())
nonpals, pals = {}, {}
for _ in range(n):
    s = input()
    if s == s[::-1]:
      pals[s] = pals.get(s, 0) + 1
    else:
      nonpals[s] = nonpals.get(s, 0) + 1
result = center = ''
for s, c in nonpals.items():
  rs = s[::-1]
  if s < rs:
    for _ in range(min(c, nonpals.get(rs, 0))):
      result += s
for s, c in pals.items():
    for _ in range(c >> 1):
      result += s
    if c % 2 == 1 and not center:
      center = s
result = result + center + result[::-1]
print(len(result))
print(result)