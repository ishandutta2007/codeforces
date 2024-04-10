n, a = int(input()), list(map(int,input().split()))
usd = [ False for i in range(n) ]
got = [ False for i in range(n) ]
for i in range(n):
  if a[i] <= n and not usd[a[i]-1]:
    got[i] = usd[a[i]-1] = True
nxt = 0
for i in range(n):
  if not got[i]:
    while usd[nxt]:
      nxt += 1
    a[i] = nxt + 1
    usd[nxt] = True
print( " ".join(str(x) for x in a) )