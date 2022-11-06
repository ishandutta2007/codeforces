MOD = 10**9 + 7


def mat_mul(m1, m2):
    n = len(m1)
    m = []
    for _ in range(n):
        m.append([0] * n)
    for y in range(n):
        for x in range(n):
            for i in range(n):
                m[y][x] += m1[y][i] * m2[i][x]
    for y in range(n):
        for x in range(n):
            m[y][x] %= (MOD - 1)
    return m


def square_and_multiply(m, exp):
    if exp == 1:
        return m

    sub = square_and_multiply(m, exp // 2)
    sqr = mat_mul(sub, sub)
    if exp % 2 == 1:
        return mat_mul(sqr, m)
    return sqr


n, f1, f2, f3, c = map(int, input().split())
mf = [
    [1, 1, 1],
    [1, 0, 0],
    [0, 1, 0],
]
mc = [
    [1, 0, 0, 0, 1],
    [2, 1, 1, 1, -4],
    [0, 1, 0, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 0, 1],
]

matf = square_and_multiply(mf, n - 3)
matc = square_and_multiply(mc, n - 3)

c_exp = matc[1][0] * 3 + matc[1][4]
f3_exp = matf[0][0]
f2_exp = matf[0][1]
f1_exp = matf[0][2]
res = pow(c, c_exp, MOD) * pow(f3, f3_exp, MOD) * pow(f2, f2_exp, MOD) * pow(f1, f1_exp, MOD)
print(res % MOD)