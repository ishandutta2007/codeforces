T = int(input())
for cc in range(0, T):
	n = int(input())
	s = input()
	for i in range(0, n):
		diff = abs(ord(s[i]) - ord(s[n-1-i]))
		if diff != 0 and diff != 2:
			print("NO")
			break
	else:
		print("YES")