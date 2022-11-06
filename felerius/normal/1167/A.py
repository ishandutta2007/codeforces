t = int(input())
for _ in range(t):
    input()
    s = input()
    try:
        pos8 = s.index('8')
    except ValueError:
        print('NO')
    else:
        print('YES' if len(s) - pos8 >= 11 else 'NO')