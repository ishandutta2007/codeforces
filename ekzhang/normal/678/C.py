from fractions import gcd
def lcm(a, b): return a * b / gcd(a, b)
n, a, b, p, q = map(int, raw_input().split())
print (n / a) * p + (n / b) * q - (n / lcm(a, b)) * min((p, q,))