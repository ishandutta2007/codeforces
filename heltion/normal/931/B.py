n,a,b=map(int,input().split())
a,b,c=a-1,b-1,0
while a!=b:
	a,b,c=a//2,b//2,c+1
if 2**c==n:
	print("Final!")
else:
	print(c)