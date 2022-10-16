s = [int(x) % 3 for x in input()]

i = 0
ans = 0
n = len(s)

while i < n:
	if s[i] == 0:
		ans += 1
		i += 1
		continue
	if s[i] == 1:
		if i + 1 < n and s[i + 1] == 2:
			ans += 1
			i += 2
			continue
		if i + 2 < n and s[i + 1] == s[i + 2] == 1:
			ans += 1
			i += 3
			continue
	if s[i] == 2:
		if i + 1 < n and s[i + 1] == 1:
			ans += 1
			i += 2
			continue
		if i + 2 < n and s[i + 1] == s[i + 2] == 2:
			ans += 1
			i += 3
			continue
	i += 1
print(ans)