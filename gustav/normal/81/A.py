s = raw_input()
t = [ s[0] ]
for i in range( 1, len(s) ):
    if len(t) and t[len(t)-1] == s[i]: t.pop()
    else: t.append( s[i] )
print ''.join( t )