a, b = map(int, input().split())

if abs(a - b) > 1 or not (a or b):
    print('NO')
else:
    print('YES')