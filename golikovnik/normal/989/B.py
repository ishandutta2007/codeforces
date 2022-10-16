# your code goes here
n, p = map(int, input().split())
s = input()
for i in range(n - p):
	x, y = s[i], s[i + p]
	if '.' in (x, y) or x != y:
		a = list(s.replace('.', '1'))
		if x == y and x == '.':
			a[i] = '1'
			a[i + p] = '0'
			print(''.join(a))
		elif x == '.':
			a[i] = str(int(y) ^ 1)
			print(''.join(a))
		elif y == '.':
			a[i + p] = str(int(x) ^ 1)
			print(''.join(a))
		else:
			print(''.join(a))
		exit()
print('No')