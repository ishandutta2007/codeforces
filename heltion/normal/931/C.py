n=int(input())
x=list(map(int,input().split()))
x.sort()
c=[0,0,0]
for i in x:
	c[i-x[0]]+=1
if max(x)-x[0]<2:
	print(n)
	for i in x:
		print(i,end=' ')
else:
	if 2*min(c[0],c[2])>=c[1]:
		print(n-2*min(c[0],c[2]))
		for i in range(c[0]-min(c[0],c[2])):
			print(x[0],end=' ')
		for i in range(c[1]+2*min(c[0],c[2])):
			print(x[0]+1,end=' ')
		for i in range(c[2]-min(c[0],c[2])):
			print(x[0]+2,end=' ')
	else:
		print(n-c[1]//2*2)
		for i in range(c[0]+c[1]//2):
			print(x[0],end=' ')
		for i in range(c[1]-c[1]//2*2):
			print(x[0]+1,end=' ')
		for i in range(c[2]+c[1]//2):
			print(x[0]+2,end=' ')