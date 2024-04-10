a = int(raw_input())

while(a % 10 == 0):
    a /= 10

s = str(a);
if(s == s[::-1]):
    print "YES"
else:
    print "NO"