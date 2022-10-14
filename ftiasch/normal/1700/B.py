for _ in range(int(input())):
    n = int(input())
    s = input()
    s0 = int(s[0])
    if s0 < 9:
        target = int("9" * n)
    else:
        target = int("1" * (n + 1))
    print(int(target) - int(s))