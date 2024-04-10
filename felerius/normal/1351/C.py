t = int(input())
for _ in range(t):
    s = set()
    x, y, ti = 0, 0, 0
    for c in input():
        ox, oy = x, y
        if c == 'W':
            x -= 1
        elif c == 'E':
            x += 1
        elif c == 'N':
            y -= 1
        elif c == 'S':
            y += 1
        if (ox, oy, x, y) in s or (x, y, ox, oy) in s:
            ti += 1
        else:
            s.add((ox, oy, x, y))
            ti += 5
    print(ti)