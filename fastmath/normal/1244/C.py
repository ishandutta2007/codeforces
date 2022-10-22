def gcd1(a, b):
    if (a == 0):
        return [0, 1]
    x1, y1 = gcd1(b%a, a)
    return [y1 - (b // a) * x1, x1]

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

n, p, a, b = map(int, input().split())
if (p % gcd(a, b)):
    print(-1)
    exit(0);
x, y = gcd1(a, b)
x *= p // gcd(a, b); 
y *= p // gcd(a, b);
step = lcm(a, b) // b;
sh = ((y % step + step) % step - y) // step;
y += sh * step;
x -= sh * (lcm(a, b) // a);
if (x + y > n or x < 0):
    print(-1)
else:
    print(x, y, n - x - y)