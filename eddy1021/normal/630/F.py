n = int( input() )
def C( a , b ):
  x, aa, bb = 1, a, b
  while bb > 0:
    x *= aa
    aa -= 1
    bb -= 1
  while b > 0:
    x //= b
    b -= 1
  return x
print( C( n , 5 ) + C( n , 6 ) + C( n , 7 ) )