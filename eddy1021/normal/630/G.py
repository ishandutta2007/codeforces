n = int( input() )
def C( a , b ):
  if a < b: return 0
  x, aa, bb = 1, a, b
  while bb > 0:
    x *= aa
    aa -= 1
    bb -= 1
  while b > 0:
    x //= b
    b -= 1
  return x
ans1 = C( n , 1 ) + 2 * C( n , 2 ) + C( n , 3 )
ans2 = C( n , 1 ) + 4 * C( n , 2 ) + 6 * C( n , 3 ) + 4 * C( n , 4 ) + C( n , 5 )
print( ans1 * ans2 )