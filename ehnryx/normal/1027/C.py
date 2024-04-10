from sys import stdin, stdout

T = int(stdin.readline())
ans = []
for cc in range(0, T):
	n = int(stdin.readline())
	a = [ int(x) for x in stdin.readline().split() ]
	a.sort()
	a.append(0x3f3f3f3f)

	res = [ 0, 0, 1, 1 ]

	pre = 0
	cnt = 0
	for i in a:
		if i == pre:
			cnt += 1
		else:
			if cnt >= 4:
				res = [ pre, pre, pre, pre ]
				break
			cnt = 1
		pre = i

	if res[0] == 0:
		pre = 0
		val = 0
		for i in a:
			if i == pre and i != val:
				if val * res[-1] > res[0] * i:
					res = [ val, val, i, i ]
				val = i
			pre = i

	ans.append(' '.join([ str(x) for x in res ]))

stdout.write('\n'.join(ans) + '\n')