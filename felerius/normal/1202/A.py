t = int(input())
for _ in range(t):
    x = input()
    y = input()
    tz = 0
    for c in reversed(y):
        if c == '1':
            break
        tz += 1
    best = 0
    for i, c in enumerate(reversed(x if tz == 0 else x[:-tz])):
        if c == '1':
            best = i
            break
    print(best)