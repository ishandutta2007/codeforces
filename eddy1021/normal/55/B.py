def cal( a , b , c ):
  if c[ 0 ] == '+':
    return int(a) + int(b)
  return int(a) * int(b)
num = input().split()
op = input().split()
def DFS( l , no ):
  if no == 3: return int( l[ 0 ] )
  else:
    ln = len( l )
    ans = 10 ** 100
    for i in range( ln ):
      for j in range( i + 1 , ln ):
        ll = []
        for k in range( ln ):
          if i != k and j != k:
            ll.append( l[ k ] )
        ll.append( cal( l[ i ] , l[ j ] , op[ no ] ) )
        ans = min( ans , DFS( ll , no + 1 ) )
    return ans
print( DFS( num , 0 ) )