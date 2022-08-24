a = raw_input()
b = input()
a = a.lower()
c = ""
for i in xrange(len(a)):
    y = a[i]
    if (ord(y) < b + 97):
        c = c + chr(ord(y) + ord('A') - ord('a'))
    else:
        c = c + y
print c