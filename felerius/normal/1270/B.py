# Contest: Good Bye 2019 (https://codeforces.com/contest/1270)
# Problem: B: Interesting Subarray (https://codeforces.com/contest/1270/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n = rint()
    a = rints()
    for i in range(n - 1):
        if abs(a[i] - a[i + 1]) >= 2:
            print('YES')
            print(i + 1, i + 2)
            break
    else:
        print('NO')