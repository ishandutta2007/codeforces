q = int(input())
for _ in range(q):
    a, b, c = sorted(map(int, input().split()))
    print(b + (c - (b - a)) // 2)