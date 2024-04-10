S=raw_input()
T="CODEFORCES"
for i in xrange(11):
    if S.startswith(T[:i]) and S.endswith(T[i:]):
        print "YES"
        raise SystemExit()
print "NO"