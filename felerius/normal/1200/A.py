n = int(input())
s = input()
r = [0] * 10
for c in s:
    if c == 'L':
        r[r.index(0)] = 1
    elif c == 'R':
        for i in reversed(range(10)):
            if r[i] == 0:
                r[i] = 1
                break
    else:
        r[int(c)] = 0
print(''.join(map(str, r)))