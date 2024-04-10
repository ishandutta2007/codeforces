m,d=list(map(int,input().split()))
dd = 31
if m == 2: dd = 28
if m == 4 or m == 6 or m == 9 or m == 11: dd = 30
a, dd = 1, dd - (8-d)
while dd > 0:
  a, dd = a+1, dd-7
print(a)