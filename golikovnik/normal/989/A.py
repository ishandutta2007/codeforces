# your code goes here
s = input()
if len(s) < 3:
	print('No')
	exit()
for x, y, z in zip(s, s[1:], s[2:]):
	if set([x, y, z]) == set('ABC'):
		print('Yes')
		exit()
print('No')