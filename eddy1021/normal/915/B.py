n,p,l,r=list(map(int,input().split()))
if p<l:
  if r<n: print(r-p+2)
  else: print(l-p+1)
elif r<p:
  if l>1: print(p-l+2)
  else: print(p-r+1)
elif l==1 and r==n: print(0)
elif l==1: print(r-p+1)
elif r==n: print(p-l+1)
else: print(r-l+min(r-p,p-l)+2)