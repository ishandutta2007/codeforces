str = raw_input()

for i in xrange(len(str)):
    if str[i] == '.':
        p = i
        a = str[:i]
        d = str[i+1:]

    if str[i] == 'e':
        d = str[p+1:i]
        b = int(str[i+1:])

a = a + d

while(b != 0):
    p += 1
    if p == len(a):
        a = a + '0'
    b -= 1

if int(a[p:]) == 0:
    a = a[:p]

else:
    a = a[:p] + '.' + a[p:]

print a