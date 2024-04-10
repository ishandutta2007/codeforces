n = int( input() )
a = input().split()
ans, pre = 1, -1
for i in range( n ):
  if int( a[ i ] ) == 1:
    if pre != -1:
      ans *= ( i - pre )
    pre = i
print( ans if pre != -1 else 0 )