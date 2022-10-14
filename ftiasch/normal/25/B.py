# Codeforces Beta Round #26
# Problem B -- Phone numbers
n = input()
s = raw_input()
t = ""
for i in xrange(n):
	t += s[i]
	if i % 2 == 1 and i < n - 2:
		t += '-'
print t