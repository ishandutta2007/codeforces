# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (17) Suffix Structures (Difficulty: 4) (http://codeforces.com/problemset/problem/448/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


def count_chars(s):
    co = [0] * 26
    for c in s:
        co[ord(c) - ord('a')] += 1
    return co


s = input()
t = input()
sc = count_chars(s)
tc = count_chars(t)
if all(sci == tci for sci, tci in zip(sc, tc)):
    print('array')
elif any(tci > sci for sci, tci in zip(sc, tc)):
    print('need tree')
else:
    i = 0
    for c in t:
        while i < len(s) and s[i] != c:
            i += 1
        i += 1
    if i <= len(s):
        print('automaton')
    else:
        print('both')