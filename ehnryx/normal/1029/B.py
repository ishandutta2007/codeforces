from sys import stdin, stdout

n = int(stdin.readline())
a = [int(x) for x in stdin.readline().split()]

ans = 0
cur = 0
pre = 0
for i in a:
	if i > pre*2:
		ans = max(ans, cur)
		cur = 1
	else:
		cur += 1
	pre = i

stdout.write(str(max(ans, cur)) + '\n')