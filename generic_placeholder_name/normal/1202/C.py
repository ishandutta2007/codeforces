import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input()
    l, r, u, d, fl, fr, fu, fd, x, y = [0] * 10
    for i in range(len(s)):
        if s[i] == 'W':
            y += 1
            if y > u:
                u = y
                fd = 0
                fu = 1
            if y == u:
                fu = 1
        elif s[i] == 'A':
            x -= 1
            if x < l:
                l = x
                fl = 1
                fr = 0
            if x == l:
                fl = 1
        elif s[i] == 'S':
            y -= 1
            if y < d:
                d = y
                fd = 1
                fu = 0
            if y == d:
                fd = 1
        elif s[i] == 'D':
            x += 1
            if x > r:
                r = x
                fr = 1
                fl = 0
            if x == r:
                fr = 1
    #bless Ctrl+C Ctrl+V
    x, y = r - l + 1, u - d + 1
    s, k = x * y, x * y
    if x > 2 and not fl * fr:
        s = k - y
    if y > 2 and not fu * fd and k - x < s:
        s = k - x
    print(s)