# Contest: Codeforces Round #577 (Div. 2) (https://codeforces.com/contest/1201)
# Problem: C: Maximum Median (https://codeforces.com/contest/1201/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, k = rints()
a = rints()
a.sort()

c = 1
m = a[n // 2]
while c <= n // 2 and k > 0:
    ne = a[n // 2 + c]
    if (ne - m) * c > k:
        break
    k -= (ne - m) * c
    m = ne
    c += 1
print(m + k // c)