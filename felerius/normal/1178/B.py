# Contest: Codeforces Global Round 4 (https://codeforces.com/contest/1178)
# Problem: B: WOW Factor (https://codeforces.com/contest/1178/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


s = input()

prev_w = 0
prev_wo = 0
cons_v = 0
wow = 0
for c in s:
    if c == 'v':
        cons_v += 1
    else:
        if cons_v > 0:
            wow += prev_wo * (cons_v - 1)
            prev_w += cons_v - 1
            cons_v = 0
        prev_wo += prev_w

if cons_v > 0:
    wow += prev_wo * (cons_v - 1)

print(wow)