def B():
  n=int(input())
  G=[list(input()) for _ in range(n)]
  for i in range(n):
    for j in range(n):
      if G[i][j] == '.':
        if i+2<n and 0<j<n-1 and G[i+1][j-1:j+2] == ['.']*3 and G[i+2][j] == '.': G[i+1][j-1:j+2],G[i+2][j]='###','#'
        else: return 1
  return 0
print("YNEOS"[B()::2])