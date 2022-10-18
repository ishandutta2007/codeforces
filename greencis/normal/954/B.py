r = input
ans = n = int(r())
s = r()
len = 1
while len * 2 <= n:
  if s[0:len] == s[len:len*2]:
    ans = min(ans, n - len + 1)
  len += 1
print(ans)