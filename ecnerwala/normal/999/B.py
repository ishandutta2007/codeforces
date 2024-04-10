n = int(input())
s = input()
for i in range(1,n+1):
  if n % i: continue
  s = s[:i][::-1] + s[i:]
print(s)