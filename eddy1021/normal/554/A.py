s = input()
n, d = len(s), dict()
for i in range(n+1):
  for j in range(26):
    d[s[0:i]+chr(j+97)+s[i:n]] = 1
print(len(d))