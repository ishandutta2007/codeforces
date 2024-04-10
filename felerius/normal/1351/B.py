t = int(input())
for _ in range(t):
    a1, b1 = sorted(map(int, input().split()))
    a2, b2 = sorted(map(int, input().split()))
    print('YES' if b1 == b2 and a1 + a2 == b1 else 'NO')