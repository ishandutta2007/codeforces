n, d = input().split()
n, d = int(n), int(d)
a = []
for i in range( n ):
  x = input().split()
  x[ 0 ], x[ 1 ] = int( x[ 0 ] ), int( x[ 1 ] )
  a.append( x )
def cmp( x ):
  return x[ 0 ]
a = sorted( a , key = cmp )
ans, acc, rptr = 0, 0, -1
#  print( a )
for i in range( n ):
  while rptr < n - 1 and a[ rptr + 1 ][ 0 ] < a[ i ][ 0 ] + d:
    rptr, acc = rptr + 1, acc + a[ rptr + 1 ][ 1 ]
  ans = max( ans , acc )
  #  print( str( i ) + " " + str( rptr ) + ":" + str( acc ) )
  acc -= a[ i ][ 1 ]
print( ans )