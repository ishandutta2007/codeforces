# Codeforces Beta Round #23
# Problem A -- You're Given a String...
s = raw_input()
a = 0
for i in range(len(s)):
	for j in range(len(s)):
		if i != j:
			k = 0
			while i + k < len(s) and j + k < len(s) and s[i + k] == s[j + k]:
				k += 1
			a = max(a, k)
print a