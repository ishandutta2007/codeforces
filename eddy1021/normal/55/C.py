n, m, k = map( int , input().split() )
flag = False
while k > 0:
  k -= 1
  x, y = map( int , input().split() )
  d = min( x , n - x + 1 , y , m - y + 1 )
  if d <= 5: flag = True
print( "YES" if flag else "NO" )