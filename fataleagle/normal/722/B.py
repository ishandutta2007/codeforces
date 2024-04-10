N = int(raw_input())
A = map(int, raw_input().split())
for i in xrange(N):
    S = raw_input()
    x = 0
    for j in "aeiouy":
        x += S.count(j)
    if x != A[i]:
        print "NO"
        break
else:
    print "YES"