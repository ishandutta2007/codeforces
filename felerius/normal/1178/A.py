# Contest: Codeforces Global Round 4 (https://codeforces.com/contest/1178)
# Problem: A: Prime Minister (https://codeforces.com/contest/1178/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
a = rints()
su = sum(a)
co = [(1, a[0])] + [(i + 2, ai) for i, ai in enumerate(a[1:]) if a[0] >= 2 * ai]
if sum(ai for _, ai in co) > su / 2:
    print(len(co))
    print(' '.join(map(str, (i for i, _ in co))))
else:
    print(0)