n, m = input().split()
n, m = int(n), int(m)
a = list( map( int , input().split() ) )
v = [ [] for _ in range( n ) ]
for i in range( n - 1 ):
  x = list( map( int , input().split() ) )
  x[ 0 ], x[ 1 ] = int(x[ 0 ]) - 1, int(x[ 1 ]) - 1
  v[ x[ 0 ] ].append( x[ 1 ] )
  v[ x[ 1 ] ].append( x[ 0 ] )
tag = [False] * n
con = [0] * n
from collections import deque as dq
d = dq()
d.append( 0 )
con[ 0 ] = a[ 0 ]
tag[ 0 ] = True
ans = 0
while len(d) > 0:
  x, chd = d.popleft(), 0
  #  print( ( x , con[ x ] ) )
  if con[ x ] > m: continue
  for y in v[x]:
    if not tag[ y ]:
      con[ y ] = con[ x ] + a[ y ] if a[ y ] == 1 else 0
      tag[ y ] = True
      chd += 1
      d.append( y )
  if chd == 0 and con[ x ] <= m:
    ans += 1
print( ans )