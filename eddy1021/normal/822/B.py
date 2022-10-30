n,m=list(map(int,input().split()))
s=input()
t=input()
a=[i for i in range(len(s)+1)]
def f(x, y):
  dif = []
  for i in range(len(x)):
    if x[i] != y[i]:
      dif.append(str(i+1))
  return dif
for i in range(len(t)-len(s)+1):
  u=f(s,t[i:i+len(s)])
  if len(u) < len(a):
    a = u
print(len(a))
print(' '.join(a))