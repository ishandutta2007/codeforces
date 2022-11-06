# Contest: Codeforces Round #415 (Div. 2) (https://codeforces.com/contest/810)
# Problem: B: Summer sell-off (https://codeforces.com/contest/810/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, f = rints()
sell = 0
over = []
for _ in range(n):
    k, l = rints()
    sell += min(k, l)
    over.append(max(0, min(2*k, l) - min(k, l)))
over.sort(reverse=True)
sell += sum(over[:f])
print(sell)