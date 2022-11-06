from collections import deque
t = int(input())
for _ in range(t):
    n = int(input())
    a = deque(map(int, input().split()))
    prev, m, x, y = 0, 0, 0, 0
    while a:
        xi, yi = 0, 0
        while a and xi <= prev:
            xi += a.popleft()
        while a and yi <= xi:
            yi += a.pop()
        if xi > 0:
            m += 1
        if yi > 0:
            m += 1
        x += xi
        y += yi
        prev = yi
    print(m, x, y)