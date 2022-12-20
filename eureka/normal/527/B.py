def gao():
	n = int(input())
	a = input()
	b = input()
	mp = {}
	cnt = 0
	for i in range(n):
		if a[i] != b[i]:
			cnt += 1
			mp[(a[i], b[i])] = i + 1
	l = [chr(ord('a') + i) for i in range(26)]
	for i in l:
		for j in l:
			if (i, j) in mp and (j, i) in mp:
				print(cnt - 2)
				print(mp[(i, j)], mp[(j, i)])
				return
	for i in l:
		for j in l:
			for k in l:
				if (i, j) in mp and (j, k) in mp:
					print(cnt - 1)
					print(mp[(i, j)], mp[(j, k)])
					return
	print(cnt)
	print(-1, -1)


gao()