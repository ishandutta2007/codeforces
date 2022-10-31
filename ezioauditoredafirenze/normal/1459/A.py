import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

for _ in range(int(input())):
	n=int(input())
	s=input()
	t=input()
	r,b=0,0
	for i in range(n):
		if s[i]>t[i]:
			r=r+1
		if t[i]>s[i]:
			b=b+1
	if r>b:
		print("RED")
	elif b>r:
		print("BLUE")
	else:
		print("EQUAL")