for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    if (n == 2 and k == 3) or (n <= 30 and k > (4 ** n - 1) // 3):
        print('NO')
    else:
        cn = n - 1
        ck = k - 1
        l = 1
        while cn * ck != 0 and ck >= 4 * l - 1:
            ck -= 4 * l - 1
            cn -= 1
            l *= 2
        print('YES', cn)