n = int(input())
s = input()

for d in range(1, n+1):
	if not n % d:
		s = s[:d][::-1] + s[d:]

print(s)