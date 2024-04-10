s = input()
try:
    i1 = s.index('h')
    i2 = s.index('e', i1)
    i3 = s.index('i', i2)
    i4 = s.index('d', i3)
    s.index('i', i4)
    print('YES')
except ValueError:
    print('NO')