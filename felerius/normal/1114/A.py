x, y, z = map(int, input().split())
a, b, c = map(int, input().split())
if x > a:
    print('NO')
else:
    if y > a + b - x:
        print('NO')
    else:
        print('NO' if z > a + b + c - x - y else 'YES')