import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

for _ in range(int(input())):
	n=int(input())
	a=inputlist()
	degree,result,answer=[0]*n,0,[]
	for i in range(n):
		result+=a[i]
	answer.append(result)
	for i in range(n-1):
		u,v=inputlist()
		u,v=u-1,v-1
		degree[u]+=1
		degree[v]+=1
	heap=[]
	for i in range(n):
		for j in range(degree[i]-1):
			heap.append(a[i])
	heap.sort(reverse=True)
	for num in heap:
		result+=num
		answer.append(result)
	printlist(answer)