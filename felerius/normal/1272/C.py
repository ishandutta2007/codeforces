# Contest: Codeforces Round #605 (Div. 3) (https://codeforces.com/contest/1272)
# Problem: C: Yet Another Broken Keyboard (https://codeforces.com/contest/1272/problem/C)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n, k = rints()
s = input()
val = set(input().split())
co = 0
cnt = 0
for c in s:
    if c in val:
        co += 1
    else:
        cnt += co * (co + 1) // 2
        co = 0
cnt += co * (co + 1) // 2
print(cnt)