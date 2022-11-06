# Contest: Educational Codeforces Round 68 (Rated for Div. 2) (https://codeforces.com/contest/1194)
# Problem: C: From S To T (https://codeforces.com/contest/1194/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


q = rint()
for _ in range(q):
    s = input()
    t = input()
    pc = [0] * 26
    for c in input():
        pc[ord(c) - ord('a')] += 1
    i = j = 0
    while i < len(t):
        if j < len(s) and t[i] == s[j]:
            i += 1
            j += 1
        else:
            pc[ord(t[i]) - ord('a')] -= 1
            if pc[ord(t[i]) - ord('a')] < 0:
                j = 0
                break
            i += 1
    print('YES' if j == len(s) else 'NO')