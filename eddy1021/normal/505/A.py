s = input()
n = len(s)
for i in range(n+1):
  for j in range(26):
    x = s[0:i]+chr(j+97)+s[i:n]
    if x == x[::-1]:
      print(x)
      exit()
print("NA")