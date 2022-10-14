def lift(n, a):
    # base: mod 5
    x = 0
    while pow(2, x, 5) != a % 5:
        x += 1
    for i in range(2, n + 1):
        mod, phi, step = pow(5, i), 4 * pow(5, i - 1), 4 * pow(5, i - 2)
        while pow(2, x, mod) != a % mod:
            x += step
            if x >= phi:
                x -= phi
    return x


def solve(a):
    n = len(str(a))

    m = 0
    while 10 ** m / (2 ** (n + m)) * 4 / 5 < n + m + 1:
        m += 1

    pw2, pw5 = 2 ** (n + m), 5 ** (n + m)
    b = a * 10 ** m % pw2
    if b != 0:
        b = pw2 - b

    while b < 10 ** m:
        if b % 5 != 0:
            k = lift(n + m, (a * 10 ** m + b) % pw5)
            if k >= n + m:
                return k
        b += pw2

for _ in range(int(input())):
    a = int(input())
    k = solve(a)
    assert str(a) in str(pow(2, k, 10 ** 100))
    print(k)