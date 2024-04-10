

q = int(input())

for i in range(q):
	inp = list(map(int, input().split()))
	n = inp[0]
	k = inp[1]
	a = list(map(int, input().split()))
	
	maxval = a[0] + k
	for j in range(n):
		val = a[j] + k
		if (val < maxval):
			maxval = val
	
	good = True
	for j in range(n):
		val = a[j] - k
		if (val > maxval):
			good = False
			
	if (not good):
		print("-1")
	else:
		print(maxval)