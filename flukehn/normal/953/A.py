import sys

array = tuple(map(int,input().split()))
l=array[0]
r=array[1]

a=[]
b=[]
c=1
while c<=2000000000:
	a.append(c)
	c*=2
c=1
while c<=2000000000:
	b.append(c)
	c*=3
p=0
for i in a:
	for j in b:
		#print(i*j)
		if i*j<=r and i*j>=l:
			p+=1
print(p)