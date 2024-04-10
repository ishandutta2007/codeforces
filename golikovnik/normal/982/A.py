n = int(input())
s = input()
ok = 1
for i in range(n):
	if s[i] == '1':
		if i > 0:
			ok &= s[i - 1] == '0'
		if i < n - 1:
			ok &= s[i + 1] == '0'
	else:
		res = 0
		if i > 0:
			res |= s[i - 1] == '1'
		if i < n - 1:
			res |= s[i + 1] == '1'
		ok &= res
print("Yes" if ok else "No")