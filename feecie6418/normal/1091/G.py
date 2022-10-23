import math
import random
import sys

n=(int)(input())
div=[]

for tmp in range(50):
	x=random.randint(1,n-1)
	y=x*x%n
	print('sqrt',y)
	sys.stdout.flush()
	z=(int)(input())
	if x!=z :
		u=math.gcd(max(0,x-z),n)
		if u!=1:
			div.append(u)
			div.append(n//u)

ans=[]
while n>1 :
	nw=[]
	cur=n
	for i in div:
		u=math.gcd(cur,i)
		if u!=1:
			cur=u
	n//=cur
	ans.append(cur)
	for i in div:
		if i!=cur:
			nw.append(i//cur)
		
	
print('!',len(ans),*ans)
sys.stdout.flush()