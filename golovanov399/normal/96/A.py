s = raw_input()
k = 1
m = 0
for i in range(len(s) - 1):
    if (s[i] == s[i + 1]):
        k = k + 1
    else:
        if (k > m):
            m = k
        k = 1
if (k > m):
    m = k
if (m > 6):
    print 'YES'
else:
    print 'NO'