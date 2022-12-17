def gao(c):
	n = len(c)
	a = [(c[i], i) for i in range(n)]
	a.sort()
	l = [0] * n
	r = [0] * n
	for i in range(1, n-1):
		l[i] = i - 1
		r[i] = i + 1
	index = [0] * n
	for i in range(n):
		index[a[i][1]] = i
	mx = 0
	for i in range(1, n):
		mx = max(mx, a[i][0] - a[i-1][0])
	ans = [mx]
	for i in range(n-1, 2, -1):
		p = index[i]
		mx = max(mx, a[r[p]][0] - a[l[p]][0])
		ans.append(mx)
		l[r[p]] = l[p]
		r[l[p]] = r[p]
	ans.reverse()
	return ans

[w, h, n] = list(map(int, raw_input().split()))
H = [0, h] + [0] * n
V = [0, w] + [0] * n
for i in range(n):
	[op, v] = raw_input().split()
	v = int(v)
	if op == 'H':
		H[i+2] = v
		V[i+2] = V[i+1]
	else:
		V[i+2] = v
		H[i+2] = H[i+1]
ansH = []
ansV = []
ansH = gao(H)
ansV = gao(V)
for i in range(n):
	print ansH[i] * ansV[i]