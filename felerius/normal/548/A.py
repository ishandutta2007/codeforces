# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (10) Mike and Fax (Difficulty: 3) (http://codeforces.com/problemset/problem/548/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


s = input()
k = rint()
if len(s) % k != 0:
    print('NO')
    exit(0)

l = len(s) // k
for i in range(k):
    s2 = s[i * l:(i + 1) * l]
    for j in range(l // 2):
        if s2[j] != s2[l - 1 - j]:
            print('NO')
            exit(0)
print('YES')