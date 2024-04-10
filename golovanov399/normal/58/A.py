s = raw_input()
k = 0
for i in range(len(s)):
    if (k == 0) and (s[i] == 'h'):
        k = 1
    elif (k == 1) and (s[i] == 'e'):
        k = 2
    elif ((k == 2) or (k == 3)) and (s[i] == 'l'):
        k = k + 1
    elif (k == 4) and (s[i] == 'o'):
        k = 5
if k == 5:
    print 'YES'
else:
    print 'NO'