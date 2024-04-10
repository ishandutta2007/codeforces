n = int(raw_input())
s = str(n).zfill(5)
s = "".join((s[0], s[2], s[4], s[3], s[1]))
n = int(s)
n **= 5
s = str(n)[-5:]
print s.zfill(5)