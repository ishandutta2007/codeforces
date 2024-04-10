for _ in range(int(input())):
    n = int(input())
    a = input()
    b = input()
    sa, sb = 0, 0
    good = True
    for i in range(n):
        sa += 2 * (a[i] == '1') - 1
        sb += 2 * (b[i] == '1') - 1
        good &= abs(sa) == abs(sb)
    good &= sa == sb
    print(['NO', 'YES'][good])