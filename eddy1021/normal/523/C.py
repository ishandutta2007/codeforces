s1 = input()
s2 = input()
len1 = len(s1)
len2 = len(s2)
l = 1
r = 0
got = 0
for i in range(0,len2):
    if s2[ i ] == s1[ got ] :
        got = got + 1
        if got == len1 :
            l = i
            break
got = len1 - 1
for j in range(0,len2):
    i = len2 - j - 1
    if s2[ i ] == s1[ got ] :
        got = got - 1
        if got < 0 :
            r = i - 1
            break
if l <= r :
    print( r - l + 1 )
else :
    print( "0" )