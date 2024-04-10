for _ in range(int(input())):
    n=int(input())
    s=input()
    if int(s[:1])<int(s[1:]):
        print('YES')
        print(2)
        print(s[:1], s[1:])
    else:
        print('NO')