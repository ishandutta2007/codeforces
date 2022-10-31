import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

for _ in range(int(input())):
	exp=int(input())
	if exp % 2 == 1:
		print(-1)
	else:
		a=[1]
		moves = 2
		exp = exp - 2
		while exp > 0:
			if exp >= 2*moves:
				a.append(0)
				moves = moves * 2
				exp = exp - moves
			else:
				a.append(1)
				moves = 2
				exp = exp - 2
		print(len(a))
		printlist(a)