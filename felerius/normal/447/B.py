# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (6) DZY Loves Strings (Difficulty: 2) (http://codeforces.com/problemset/problem/447/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


s = input()
k = rint()
w = rints()
mw = max(w)
print(sum((w[ord(s[i]) - ord('a')] if i < len(s) else mw) * (i + 1) for i in range(len(s) + k)))