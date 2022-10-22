for _ in range( int( input() ) ):
    sl = int( input() ); s = input()
    if s[0] != '9':
        print( str( int('9'*sl) - int(s) ) )
    else:
        print( str( int('1'*(sl+1)) - int(s) ) )