# Contest: Codeforces Round #501 (Div. 3) (https://codeforces.com/contest/1015)
# Problem: B: Obtaining the String (https://codeforces.com/contest/1015/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
s = list(input())
t = list(input())
if sorted(s) != sorted(t):
    print(-1)
    exit(0)
m = []
for i in range(n):
    j = s[i:].index(t[i]) + i
    while j > i:
        s[j - 1], s[j] = s[j], s[j - 1]
        m.append(j)
        j -= 1
print(len(m))
print(*m)