x1, y1 = input().split()
x2, y2 = input().split()
x3, y3 = input().split()
x1 = int( x1 )
x2 = int( x2 )
x3 = int( x3 )
y1 = int( y1 )
y2 = int( y2 )
y3 = int( y3 )
ans = 3
if x1 == x2 and ( y3 >= max( y1 , y2 ) or y3 <= min( y1 , y2 ) ): ans = 2
if x1 == x3 and ( y2 >= max( y1 , y3 ) or y2 <= min( y1 , y3 ) ): ans = 2
if x2 == x3 and ( y1 >= max( y2 , y3 ) or y1 <= min( y2 , y3 ) ): ans = 2
if y1 == y2 and ( x3 >= max( x1 , x2 ) or x3 <= min( x1 , x2 ) ): ans = 2
if y1 == y3 and ( x2 >= max( x1 , x3 ) or x2 <= min( x1 , x3 ) ): ans = 2
if y2 == y3 and ( x1 >= max( x2 , x3 ) or x1 <= min( x2 , x3 ) ): ans = 2
if x1 == x2 and x2 == x3: ans = 1
if y1 == y2 and y2 == y3: ans = 1
print( ans )