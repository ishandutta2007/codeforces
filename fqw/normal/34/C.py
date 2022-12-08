import sys

xs = sorted([int(s) for s in sys.stdin.readline().strip().split(',')])
rs = []
l = r = xs[0]
for x in xs[1:]:
    if x == r:
        continue
    if x == r + 1:
        r = x
    else:
        if l == r:
            rs.append(str(l))
        else:
            rs.append(str(l) + '-' + str(r))
        l = r = x
if l == r:
    rs.append(str(l))
else:
    rs.append(str(l) + '-' + str(r))

print ','.join(rs)