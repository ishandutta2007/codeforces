s = input()
n = i = e = t = 0
for j in range(0,len(s)):
	if s[j] == 'n':
		n += 1
	if s[j] == 'i':
		i += 1
	if s[j] == 'e':
		e += 1
	if s[j] == 't':
		t += 1
if n >= 3:
	print(min((n - 3) // 2 + 1,i,e // 3,t))
else:
	print(0)