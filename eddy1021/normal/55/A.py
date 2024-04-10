x = int( input() )
print( "NO" if x & x-1 > 0 else "YES" )