n = int( input() )
d = str( input() )
p = input().split()
ans = -1
for i in range( 1 , n ):
  if d[ i - 1 ] == 'R' and d[ i ] == 'L':
    tans = ( int( p[ i ] ) - int( p[ i - 1 ] ) ) // 2
    if ans == -1 or tans < ans:
      ans = tans
print( ans )