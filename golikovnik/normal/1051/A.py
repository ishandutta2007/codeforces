t = int(input())
for _ in range(t):
	s = input()
	n = len(s)
	ndig = 0
	idig = -1
	nlow = 0
	ilow = -1
	nupp = 0
	iupp = -1
	for i, c in enumerate(s):
		if c.isnumeric():
			ndig += 1
			idig = i
		elif c.isupper():
			nupp += 1
			iupp = i
		else:
			nlow += 1
			ilow = i
	ans = list(s)
	if min(ndig, nlow, nupp):
		print(s)
		continue
	elif not max(ndig, nlow, nupp):
		print('Aa1' + s[3:])
		continue
	elif not ndig and not nlow and nupp:
		if iupp + 2 < n:
			ans[iupp + 1: iupp + 3] = ['1', 'a']
		else:
			ans[:2] = ['1', 'a']
	elif not ndig and nlow and not nupp:
		if ilow + 2 < n:
			ans[ilow + 1: ilow + 3] = ['1', 'A']
		else:
			ans[:2] = ['1', 'A']
	elif not ndig and nlow and nupp:
		ans[next(iter(set(range(n)) - set([iupp, ilow])))] = '1'
	elif ndig and not nlow and not nupp:
		if idig + 2 < n:
			ans[idig + 1: idig + 3] = ['A', 'a']
		else:
			ans[:2] = ['A', 'a']
	elif ndig and not nlow and nupp:
		ans[next(iter(set(range(n)) - set([iupp, idig])))] = 'a'
	else:
		ans[next(iter(set(range(n)) - set([idig, ilow])))] = 'A'
	print(''.join(ans))