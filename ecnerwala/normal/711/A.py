n = int(input())
a = '\n'.join(input() for i in range(n))
if 'OO' in a:
   print('YES')
   i = a.index('OO')
   a = a[:i] + '++' + a[i+2:]
   print(a)
else:
   print('NO')