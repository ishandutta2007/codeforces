import sys

A = int(input())
B = A

deg = 0
mods = 0
sum = 0
while (A > 0):
    mods = mods + A % 12
    sum = sum + deg * (A % 12)
    deg = deg + 1
    A /= 12

if (mods != 2):
    print "NO"
    sys.exit()

print "YES"
print 1
print sum + 1
print sum / 2
for i in range(sum / 2, -1, -1):
    C = 12 ** i + 12 ** (sum - i)
    if (B != C):
        print C