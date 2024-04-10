n = int( input() )
ans = 2 * 4 * 3 * (int)( 4 ** ( n - 3 ) )
ans += ( n - 3 ) * 4 * 3 * 3 * (int)( 4 ** ( n - 4 ) )
print( ans )