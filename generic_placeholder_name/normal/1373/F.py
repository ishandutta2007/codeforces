import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    ok = False
    w = 0
    for i in range(1, n * 2):
        w = max(0, w) + a[i % n] - b[(i - 1) % n]
        if w > b[i % n]:
            ok = True
            break
    ok |= sum(a) - sum(b) > 0
    print(['YES', 'NO'][ok])