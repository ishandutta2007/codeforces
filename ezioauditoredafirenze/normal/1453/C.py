import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')
up = (int)(1e18)

for _ in range(int(input())):
	n=int(input())
	mat=[]
	for i in range(n):
		mat.append(input())
	a,c,answer=(10)*[0],(10)*[0],(10)*[0]
	b,d=(10)*[up],(10)*[up]
	for i in range(n):
		for j in range(n):
			digit=int(mat[i][j])
			a[digit]=max(a[digit],i)
			b[digit]=min(b[digit],i)
			c[digit]=max(c[digit],j)
			d[digit]=min(d[digit],j)
	for i in range(n):
		for j in range(n):
			digit=int(mat[i][j])
			answer[digit]=max(answer[digit],max(max(i,n-i-1)*max(j-d[digit],c[digit]-j),max(j,n-j-1)*max(i-b[digit],a[digit]-i)))
	printlist(answer)