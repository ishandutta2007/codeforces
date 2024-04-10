n, m, k = list(map(int,input().split()))
def g(a,b,d):
  return (a+a+(b-1)*d)*b//2
def f(x):
  return g(x,min(x,k),-1) + g(x-1,min(x-1,n-k),-1)
bl, br, ba = 1, m-n, 0
while bl <= br:
  mid = (bl + br) >> 1
  if f(mid) <= m-n:
    ba, bl = mid, mid + 1
  else:
    br = mid - 1
print(1+ba)