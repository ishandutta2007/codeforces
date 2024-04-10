n = int( input() )
ans = 1
for i in range( 5 ):
  ans *= ( n - i ) * ( n - i )
ans //= 120
print( ans )