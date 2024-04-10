s = raw_input()
a = 0
for c in s:
	if c == 'Q':
		a += 1
ans = 0
b = 0
for c in s:
	if c == 'Q':
		b += 1
	elif c == 'A':
		ans += b * (a-b)
print ans