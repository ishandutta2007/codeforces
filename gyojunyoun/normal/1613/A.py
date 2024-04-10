T = int(input())
for _ in range(T):
	a, ac = map(int, input().split())
	b, bc = map(int, input().split())

	mn = min(ac, bc)
	ac = ac - mn
	bc = bc - mn

	if abs(ac - bc) >= 17:
		print('>' if ac > bc else '<')
	else:
		a = a * (10 ** ac)
		b = b * (10 ** bc)

		if a == b:
			print('=')
		else:
			print('>' if a > b else '<')