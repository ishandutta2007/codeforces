import random
import math
from sys import stdout
n=(int)(input())
vec=[]
for i in range(50):
	x=random.randint(0,n)
	print("sqrt %d"%(x*x%n))
	stdout.flush()
	y=(int)(input())
	if x!=y:
		if x>y:
			x,y=y,x
		x=math.gcd(x-y,n)
		vec.append(x)
		vec.append(n//x)
ans=[]
while n>1:
	p=n
	for i in range(0,len(vec)):
		tmp=math.gcd(p,vec[i])
		if tmp!=1:
			p=tmp
	for i in range(0,len(vec)):
		if vec[i]%p==0:
			vec[i]//=p
	n//=p
	ans.append(p)
print("! %d"%(len(ans)),end=' ')
for i in ans:
	print(i,end=' ')
print()
stdout.flush()