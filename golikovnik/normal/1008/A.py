s = input()
ok = 1
n = len(s)

def is_vowel(c):
	return c in "aouie"

for i, x in enumerate(s):
	if not is_vowel(x) and x != 'n':
		ok &= ((i + 1 < n) and is_vowel(s[i + 1]))

print("YES" if ok else "NO")