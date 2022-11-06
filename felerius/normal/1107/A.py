q = int(input())
for _ in range(q):
    input()
    s = input()
    if len(s) == 2 and int(s[0]) >= int(s[1]):
        print('NO')
    else:
        print('YES')
        print(2)
        m = len(s) // 2
        if len(s) > 2 and len(s) % 2 == 0:
            m -= 1
        print(s[:m], s[m:])