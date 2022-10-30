t, s, x = map( int ,input().split() )
flag = False
if x == t: flag = True
elif x > t:
  x -= t
  d, r = x // s, x % s
  if d >= 1 and r <= 1:
    flag = True
print( "YES" if flag else "NO" )