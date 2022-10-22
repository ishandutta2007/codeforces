def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


n, m, z = map(int, input().split())
print(z // ((n * m) // gcd(n, m)))