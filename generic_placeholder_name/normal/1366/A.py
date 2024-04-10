for _ in range(int(input())):
    x, y = list(map(int, input().split()))
    if x < y:
        x, y = y, x
    r = min(y, x - y)
    x -= 2 * r 
    y -= r
    m = min(x, y) - min(x, y) % 3
    x -= m
    y -= m
    if (x >= 2 and y >= 1) or (x >= 1 and y >= 2):
        r += 1
    print(r + m // 3 * 2)