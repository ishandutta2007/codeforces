
a = raw_input().lower()
b = int(raw_input())

ans = ""

for i in range(len(a)):
  c = a[i]
  if (ord(c) < b + 97): ans += c.upper()
  else: ans += c.lower()

print(ans)