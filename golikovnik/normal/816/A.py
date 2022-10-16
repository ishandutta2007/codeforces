# your code goes here
sh, sm = map(int, input().split(':'))
mins = sh * 60 + sm
can = []
for h in range(24):
	ms = int("{:02d}".format(h)[::-1])
	if 0 <= ms < 60:
		can.append(h * 60 + ms)
can.append(24 * 60)
print(min(k for k in can if k >= mins) - mins)