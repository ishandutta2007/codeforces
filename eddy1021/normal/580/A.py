n = int( input() )
a = input().split();
ans, tans, pre = 1, 0, int(a[ 0 ])
for i in range( n ):
  a[ i ] = int( a[ i ] )
  if a[ i ] >= pre:
    tans += 1
    ans = max( ans , tans )
  else:
    tans = 1
  pre = a[ i ]
print( ans )