s = input()
s2 = ''
while s:
    if len(s) % 2 == 0:
        s2 = s[-1:] + s2
        s = s[:-1]
    else:
        s2 = s[:1] + s2
        s = s[1:]
print(s2)