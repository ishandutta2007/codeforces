n=int(input())
for _ in range(n):
 s = input()
 c0 = any('a'<=c<='z' for c in s)
 c1 = any('A'<=c<='Z' for c in s)
 c2 = any('0'<=c<='9' for c in s)
 if c0 and c1 and c2:
  print(s)
 elif c0 + c1 + c2 == 1:
  if c0: print('A0'+s[2:])
  elif c1: print('a0'+s[2:])
  elif c2: print('aA'+s[2:])
 elif not c0:
  if ('A'<=s[1]<='Z')==('A'<=s[2]<='Z'):
   print(s[0]+'a'+s[2:])
  else:
   print('a'+s[1:])
 elif not c1:
  if ('a'<=s[1]<='z')==('a'<=s[2]<='z'):
   print(s[0]+'A'+s[2:])
  else:
   print('A'+s[1:])
 else:
  if ('a'<=s[1]<='z')==('a'<=s[2]<='z'):
   print(s[0]+'0'+s[2:])
  else:
   print('0'+s[1:])