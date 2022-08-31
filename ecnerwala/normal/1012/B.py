import sys
n,m,q=map(int,input().split())
p=[-1]*(n+m)
r=[0]*(n+m)
def par(i):
 if p[i]==-1: return i
 p[i]=par(p[i])
 return p[i]
def merge(a,b):
 a,b=par(a),par(b)
 if a==b: return 0
 if r[a]<r[b]:p[a]=b
 elif r[b]<r[a]:p[b]=a
 else:p[a]=b;r[b]+=1
 return 1
v=n+m
for l in sys.stdin.read().strip().split('\n') if q else []:
 a,b=map(int,l.split())
 v-=merge(a-1,b-1+n)
print(v-1)