M = 10**9 + 7


def types(n):
    if n % 3 == 0:
        return n // 3, n // 3, n // 3
    elif n % 3 == 1:
        return n // 3, n // 3 + 1, n // 3
    return n // 3, n // 3 + 1, n // 3 + 1


n, l, r = map(int, input().split())

nr0, nr1, nr2 = types(r)
nl0, nl1, nl2 = types(l - 1)
n0, n1, n2 = nr0 - nl0, nr1 - nl1, nr2 - nl2

c0, c1, c2 = 1, 0, 0
for _ in range(n):
    c0n = c0 * n0 + c1 * n2 + c2 * n1
    c1n = c0 * n1 + c1 * n0 + c2 * n2
    c2n = c0 * n2 + c1 * n1 + c2 * n0
    c0, c1, c2 = c0n % M, c1n % M, c2n % M

print(c0)