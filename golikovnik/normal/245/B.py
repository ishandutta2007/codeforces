from re import finditer

s = input().strip()
res = ""
if s.startswith("http"):
	res += "http"
	s = s[4:]
else:
	res += "ftp"
	s = s[3:]
i = -1
for m in finditer("ru", s):
	if m.start() == 0:
		continue
	i = m.start()
	break
if i != len(s) - 2:
	res += r"://{}.ru/{}".format(s[:i], s[i + 2:])
else:
	res += r"://{}.ru".format(s[:i])
print(res)