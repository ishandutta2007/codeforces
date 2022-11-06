h, w = map(int, input().split())
lines = [input() for _ in range(h)]
total = sum(sum(1 for c in l if c == '*') for l in lines)
cx = 0
cy = 0
b = False
for y in range(1, h - 1):
    for x in range(1, w - 1):
        if lines[y][x] == '*' and lines[y][x - 1] == '*' and lines[y][x + 1] == '*' and lines[y - 1][x] == '*' and lines[y + 1][x] == '*':
            cx = x
            cy = y
            b = True
            break
    if b:
        break

if cx == 0:
    print('NO')
    exit(0)

size = 1
for dx in range(1, cx + 1):
    if lines[cy][cx - dx] == '*':
        size += 1
    else:
        break
for dx in range(1, w - cx):
    if lines[cy][cx + dx] == '*':
        size += 1
    else:
        break
for dy in range(1, cy + 1):
    if lines[cy - dy][cx] == '*':
        size += 1
    else:
        break
for dy in range(1, h - cy):
    if lines[cy + dy][cx] == '*':
        size += 1
    else:
        break
if size == total:
    print('YES')
else:
    print('NO')