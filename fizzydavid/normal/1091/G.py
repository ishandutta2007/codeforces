from random import *
from math import *
n = int(input())
ans = [n]

def split_ans(t):
    ret = []
    for x in ans:
        g = gcd(x, t)
        ret.append(g)
        ret.append(x//g)
    return ret

for i in range(15):
    x = randint(1, n-1)
    print("sqrt", x*x%n)
    y = int(input())
    ans = list(set(split_ans(x+y)))

ans = sorted(ans)
print("!",len(ans)-1, *ans[1:])