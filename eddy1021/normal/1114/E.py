import math
import random
import sys
n=int(input())
if n<=60:
  a=[]
  for i in range(n):
    sys.stdout.write('? {}\n'.format(i+1))
    sys.stdout.flush()
    a.append(int(input()))
  a=list(sorted(a))
  sys.stdout.write('! {} {}\n'.format(a[0], a[1]-a[0]))
  sys.stdout.flush()
  exit(0)
res=60
mx, l, r=0, 1, 10**9
while l<=r:
  md=(l+r)>>1
  sys.stdout.write('> {}\n'.format(md-1))
  sys.stdout.flush()
  res-=1
  ret=int(input())
  if ret==1: mx, l=md, md+1
  else: r=md-1
cand=set()
while len(cand)<res: cand.add(random.randint(1, n))
a=set()
a.add(mx)
for i in cand:
  sys.stdout.write('? {}\n'.format(i))
  sys.stdout.flush()
  a.add(int(input()))
a=list(sorted(list(a)))
if len(a)==1: g=0
else: g=a[1]-a[0]
for i in range(1, len(a)):
  for j in range(i):
    g=math.gcd(g, a[i]-a[j])
a0=a[-1]-(n-1)*g
assert a0>=0
sys.stdout.write('! {} {}\n'.format(a0, g))
sys.stdout.flush()