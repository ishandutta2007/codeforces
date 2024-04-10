# Contest: Codeforces Round #577 (Div. 2) (https://codeforces.com/contest/1201)
# Problem: B: Zero Array (https://codeforces.com/contest/1201/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
a = rints()
ma = max(a)
su = sum(a)
print('NO' if su % 2 == 1 or ma > su // 2 else 'YES')