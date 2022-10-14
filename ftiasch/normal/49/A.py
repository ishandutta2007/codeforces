# Codeforces Beta Round #46
# Problem A -- Sleuth
for c in raw_input().upper()[::-1]:
	if 65 <= ord(c) <= 90:
		print c in ['A', 'E', 'I', 'O', 'U', 'Y'] and "YES" or "NO"
		break