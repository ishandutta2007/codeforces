# Contest: Educational Codeforces Round 71 (Rated for Div. 2) (https://codeforces.com/contest/1207)
# Problem: E: XOR Guessing (https://codeforces.com/contest/1207/problem/E)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


import sys
ints1 = range(100)
ints2 = ((i + 1) << 7 for i in range(100))
print(f'? ' + ' '.join(map(str, ints1)))
sys.stdout.flush()
a1 = rint()
print(f'? ' + ' '.join(map(str, ints2)))
sys.stdout.flush()
a2 = rint()
print(f'! {a1 & 0xFF80 | a2 & 0x7F}')