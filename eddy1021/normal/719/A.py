n = int( input() )
a = list(map(int,input().split()))
if len(a)==1:
  print( -1 if a[0] != 15 and a[0] != 0 else ( "UP" if a[0] == 0 else "DOWN" ) )
  exit()
if a[-1] < 15 and ( a[-1] == 0 or a[-1] > a[-2] ):
  print( "UP" )
else:
  print( "DOWN" )