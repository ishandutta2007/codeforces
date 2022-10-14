from math import sqrt, gcd


def solve(b, q, y, c, r, z):
    if c < b or (c - b) % q != 0 or c + r * z - r > b + q * y - q or r % q != 0:
        return 0
    if c - r < b or c + r * z > b + q * y - q:
        return -1
    ans = 0
    for i in range(1, int(sqrt(r) + 1)):
        if r % i == 0:
            if i * q == gcd(i, q) * r:
                ans += (r // i) ** 2
            if i * i != r and gcd(q, r // i) * i == q:
                ans += i ** 2
    return ans % 1_000_000_007


for _ in range(int(input())):
    b, q, y = map(int, input().split())
    c, r, z = map(int, input().split())
    print(solve(b, q, y, c, r, z))