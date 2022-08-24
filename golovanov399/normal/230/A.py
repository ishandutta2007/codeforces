import sys

s, n = map(int, raw_input().split())
a = [list(map(int, raw_input().split())) for i in range(n)]
while True:
    pos = 0
    for i in range(len(a)):
        if a[i][0] < a[pos][0]:
            pos = i
    if s > a[pos][0]:
        s += a[pos][1]
        a = a[:pos] + a[pos+1:] if pos < len(a) - 1 else a[:pos]
    else:
        print "NO"
        sys.exit(0)
    if len(a) == 0:
        break

print "YES"