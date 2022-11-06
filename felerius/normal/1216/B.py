# Contest: Codeforces Round #587 (Div. 3) (https://codeforces.com/contest/1216)
# Problem: B: Shooting (https://codeforces.com/contest/1216/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
a = rints()
ai = list(range(n))
ai.sort(key=lambda i: a[i], reverse=True)
s = 0
for i, idx in enumerate(ai):
    s += a[idx] * i + 1
print(s)
print(' '.join(str(i + 1) for i in ai))