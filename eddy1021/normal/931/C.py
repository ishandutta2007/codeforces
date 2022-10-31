n=int(input())
x=input()
a=list(map(int,x.split()))
if max(a)-min(a)<2:
  print(n)
  print(x)
  exit(0)
s=set(a)
q=min(a)
s=max(a)
r=(q+s)//2
m={}
m[q]=m[s]=m[r]=0
for i in a:m[i]+=1
if n-2*min(m[q],m[s])<n-m[r]//2*2:
  print(n-2*min(m[q],m[s]))
  e=min(m[q],m[s])
  m[r]+=e+e
  m[q]-=e
  m[s]-=e
else:
  print(n-m[r]//2*2)
  e=m[r]//2
  m[r]-=e+e
  m[q]+=e
  m[s]+=e
b=[r for i in range(m[r])]
b=b+[q for i in range(m[q])]
b=b+[s for i in range(m[s])]
print(' '.join(str(x) for x in b))