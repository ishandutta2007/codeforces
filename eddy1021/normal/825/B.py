s = [ [ c for c in input() ] for i in range(10) ]
def win():
  for i in range(10):
    for j in range(10):
      ok = True
      for k in range(5):
        if j+k>9: ok = False
        elif s[i][j+k] != 'X': ok = False
      if ok: return True
      ok = True
      for k in range(5):
        if i+k>9: ok = False
        elif s[i+k][j] != 'X': ok = False
      if ok: return True
      ok = True
      for k in range(5):
        if j+k>9 or i+k>9: ok = False
        elif s[i+k][j+k] != 'X': ok = False
      if ok: return True
      ok = True
      for k in range(5):
        if i-k<0 or j+k>9: ok = False
        elif s[i-k][j+k] != 'X': ok = False
      if ok: return True
  return False
for i in range(10):
  for j in range(10):
    if s[i][j]=='.':
      s[i][j] = 'X'
      if win():
        print('YES')
        exit(0)
      s[i][j] = '.'
print('NO')