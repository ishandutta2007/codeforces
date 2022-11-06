# Contest: Codeforces Round #577 (Div. 2) (https://codeforces.com/contest/1201)
# Problem: A: Important Exam (https://codeforces.com/contest/1201/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, m = rints()
s = [input() for _ in range(n)]
a = rints()

t = 0
for i in range(m):
    c = [0] * 5
    for si in s:
        c[ord(si[i]) - ord('A')] += 1
    t += a[i] * max(c)
print(t)