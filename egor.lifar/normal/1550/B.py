t = int(input())
for i in range(t):
	(ns, ass, bss) = (str(input())).split(' ')
	(n, a, b) = (int(ns), int(ass), int(bss))
	s = str(input())
	ans = n * a
	if b > 0:
		ans += n * b
	else:
		last = '2'
		cnt = 0
		for c in s:
			if c != last:
				last = c
				cnt += 1
		need = cnt // 2 + 1
		ans += need * b
	print(ans)