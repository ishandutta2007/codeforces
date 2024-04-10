s = 3 * [ 0 ]
for i in range( input() ):
    s = map( sum, zip( s, map( int, raw_input().split() ) ) )
print [ "NO", "YES" ][ s == 3 * [ 0 ] ]