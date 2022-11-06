# Contest: Codeforces Round #597 (Div. 2) (https://codeforces.com/contest/1245)
# Problem: B: Restricted RPS (https://codeforces.com/contest/1245/problem/B)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    n = rint()
    a, b, c = rints()
    s = input()
    al = [None] * n
    for i, ch in enumerate(s):
        if ch == 'R' and b > 0:
            b -= 1
            al[i] = 'P'
        elif ch == 'P' and c > 0:
            c -= 1
            al[i] = 'S'
        elif ch == 'S' and a > 0:
            a -= 1
            al[i] = 'R'
    w = sum(1 for p in al if p is not None)
    if w < (n + 1) // 2:
        print('NO')
        continue
    for i in range(n):
        if al[i] is not None:
            continue
        if a > 0:
            a -= 1
            al[i] = 'R'
        elif b > 0:
            b -= 1
            al[i] = 'P'
        else:
            c -= 1
            al[i] = 'S'
    print('YES')
    print(''.join(al))