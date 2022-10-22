def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

t, a, b = map(int, input().split())
p = min(a, b) * (t // lcm(a, b)) - 1

l = (t // lcm(a, b)) * lcm(a, b)
r = min(t, l + min(a, b) - 1)
p += r - l + 1

q = t

d = gcd(p, q)
p //= d
q //= d

print(p, '/', q, sep = '')