n, m = input().split()
n, m = int(n), int(m)
s = []
for i in range(n): s.append( str( input() ) )
cnt, cntr, cntc = 0, [], []
for i in range(n):
  tcnt = 0
  for j in range(m):
    if s[i][j] == '*':
      tcnt += 1
  cntr.append( tcnt )
for i in range(m):
  tcnt = 0
  for j in range(n):
    if s[j][i] == '*':
      tcnt += 1
      cnt += 1
  cntc.append( tcnt )
ai , aj = -1, -1
for i in range(n):
  for j in range(m):
    tmp = cntr[i] + cntc[j]
    if s[i][j] == '*': tmp -= 1
    if tmp == cnt:
      ai, aj = i, j
if ai == -1: print( "NO" )
else:
  print( "YES" )
  print( str( ai + 1 ) + " " + str( aj + 1 ) )