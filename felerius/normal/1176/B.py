t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    c = [0, 0, 0]
    for i in a:
        c[i % 3] += 1
    if c[1] >= c[2]:
        print(c[0] + c[2] + (c[1] - c[2]) // 3)
    else:
        print(c[0] + c[1] + (c[2] - c[1]) // 3)