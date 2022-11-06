n = int(input())
x = 0
loops = []
for _ in range(n):
    if x >= 2**32:
        break
    l = input()
    if l.startswith('for '):
        mul = int(l[4:])
        loops.append((x, mul))
    elif l.startswith('end'):
        old_x, mul = loops.pop()
        x = old_x + mul * (x - old_x)
    else:
        x += 1
if x >= 2**32:
    print('OVERFLOW!!!')
else:
    print(x)