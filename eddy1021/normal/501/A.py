a, b, c, d = list(map(int,input().split()))
def sc(p,t):
  return max(p*3//10, p-p*t//250)
if sc(a,c) == sc(b,d):
  print("Tie")
  exit(0)
print("Misha" if sc(a,c)>sc(b,d) else "Vasya")