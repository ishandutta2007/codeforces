x1, y1 = input().split()
x2, y2 = input().split()
print( max( abs( int( x1 ) - int( x2 ) ) , abs( int( y1 ) - int( y2 ) ) ) )