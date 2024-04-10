a = input().split("+")
a.sort()
s = ""
for c in a:
    s += c + '+'
print(s[:-1])