from sys import stdin, stdout

n, q = map(int, stdin.readline().split())
ans = []
for line in stdin:
	x, y = map(int, line.split())
	if x % 2 == y % 2:
		ans.append(str(((x-1)*n + (y-1))//2 + 1))
	else:
		ans.append(str(((x-1)*n + (y-1))//2 + 1 + (n*n+1)//2))
stdout.write('\n'.join(ans) + '\n')