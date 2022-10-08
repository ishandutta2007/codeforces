(n, x, y) = map(int, input().split())
a = list(map(int, input().split()))

for i in range(len(a)):
	minval = 1000000001
	for left in range(1, x+1):
		if i - left < 0:
			continue
		minval = min(minval, a[i - left])
	
	for right in range(1, y+1):
		if i + right >= len(a):
			continue
		minval = min(minval, a[i + right])
		
	if a[i] < minval:
		print(i+1)
		break