r = input
n = int(r())
ans = n
s = r()
i = 0
while i + 1 < n:
  if s[i:i + 2] == 'UR' or s[i:i + 2] == 'RU':
    ans -= 1
    i += 1
  i += 1
print(ans)