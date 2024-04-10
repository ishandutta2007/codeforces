s = input()
x = int(input())
if s == 'AGC':
 print('YES' if x >= 1200 else 'NO')
elif s == 'ARC':
 print('YES' if x < 2800 else 'NO')
elif s == 'ABC':
 print('YES' if x < 2000 else 'NO')
else:
 assert False
 print('NO')