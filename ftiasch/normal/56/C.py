# Codeforces Beta Round #52
# Problem C -- Corporation Mail
buf = raw_input()
ans, sta = 0, [""]
for c in buf:
	if c == ':' or c == ',':
		sta.append("")
	elif c == '.':
		tmp = sta.pop()
		for s in sta:
			if tmp == s:
				ans += 1
	else:
		sta[-1] += c
print ans