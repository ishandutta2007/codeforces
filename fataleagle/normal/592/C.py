from fractions import gcd
def lcm(a, b):
    return a * b / gcd(a, b)
n, a, b = map(long, raw_input().split())
ans = (n / lcm(a, b) + 1) * min(a, b)
ans -= max(0, (min(a, b) - 1) + lcm(a, b) * (n / lcm(a, b)) - n) + 1
if ans == 0:
    print "0/1"
else:
    g = gcd(ans, n)
    print "%d/%d" % (ans / g, n / g)