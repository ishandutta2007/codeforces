s = raw_input()
flag = False
for i in range(len(s)):
    flag = flag or (s[i] == 'H') or (s[i] == 'Q') or (s[i] == '9')
if (flag == True):
    print "YES"
else:
    print "NO"