# Contest: Educational Codeforces Round 22 (https://codeforces.com/contest/813)
# Problem: B: The Golden Age (https://codeforces.com/contest/813/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


x, y, l, r = rints()
li = [l - 1, r + 1]
for i in range(65):
    for j in range(65):
        s = x**i + y**j
        if l <= s <= r:
            li.append(s)
li = sorted(li)
mx = 0
for i in range(len(li) - 1):
    mx = max(mx, li[i + 1] - li[i] - 1)
print(mx)