raw_input()
s=raw_input()
t=raw_input()

def check(s, t):
    if not '*' in s:
        return s==t
    else:
        a, b=s.split('*')
        #print a, b
        if len(a+b)<=len(t) and t.find(a)==0 and len(t)-t.rfind(b)==len(s)-s.find('*')-1:
            return True
        else: return False
if check(s, t): print "YES"
else: print "NO"