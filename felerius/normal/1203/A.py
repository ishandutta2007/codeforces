q = int(input())
for _ in range(q):
    n = int(input())
    p = list(map(int, input().split()))
    i = p.index(1)
    p2 = p[i:] + p[:i]
    if p2 == list(range(1, n + 1)) or p2[1:] == list(reversed(range(2, n + 1))):
        print('YES')
    else:
        print('NO')