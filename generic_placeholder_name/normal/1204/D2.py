s=[*input()]
c = m = 0
for i in range(len(s) - 1, -1, -1):
	c += -1 if s[i] == '0' else 1
	if c > m:
		s[i] = '0'
		m = c
print(''.join(s))