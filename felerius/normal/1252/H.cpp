# Contest: Educational Codeforces Round 75 (Rated for Div. 2) (https://codeforces.com/contest/1251)
# Problem: A: Broken Keyboard (https://codeforces.com/contest/1251/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    s = input()
    w = [False] * 26
    i = 0
    while i < len(s):
        if i + 1 < len(s) and s[i] == s[i + 1]:
            i += 2
        else:
            w[ord(s[i]) - ord('a')] = True
            i += 1
    for i in range(26):
        if w[i]:
            print(chr(ord('a') + i), end='')
    print()