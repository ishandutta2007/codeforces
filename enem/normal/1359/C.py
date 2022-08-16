import os.path
from math import gcd, floor, ceil
from collections import *
import sys
mod = 1000000007
INF = float('inf')
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")


if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    def fun(odd):
        hot = (odd+1)//2
        cold = odd - hot
        total = (cold*c + hot*h)
        return total

    h, c, temp = mp()
    if temp == h:
        pr(1)
        return
    if h + c - 2*temp >= 0:
        pr(2)
        return
    low, high = 1, 10000000
    ans = INF
    while low <= high:
        mid = (low+high)//2
        odd = 2*mid - 1
        total = fun(odd)
        if total > temp*odd:
            low = mid + 1
        else:
            ans = odd
            high = mid - 1
    cur = [ans-2, ans]
    hi = [abs(temp*(ans-2) - fun(ans-2))*ans, abs(temp*ans-fun(ans))*(ans-2)]
    pr(cur[hi.index(min(hi))])


for _ in range(inp()):
    solve()