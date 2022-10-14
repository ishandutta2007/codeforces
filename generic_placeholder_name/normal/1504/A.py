for _ in range(int(input())):
    s = input()
    s1 = 'a' + s
    s2 = s + 'a'
    if s1[::-1] != s1:
        print('YES')
        print(s1)
    elif s2[::-1] != s2:
        print('YES')
        print(s2)
    else:
        print('NO')