s = input().split(' ')
k = int(s[0])
l = int(s[1])
r = int(s[2])
t = int(s[3])
x = int(s[4])
y = int(s[5])
def exgcd(a, b):
    if b == 0:
        return (a, 1, 0)
    d, x, y = exgcd(b, a % b)
    return (d, y, x - a // b * y)
if x >= y:
    if k + y > r:
        print("No" if k + y * (t - 1) - x * t < l  else "Yes")
    else:
        print("No" if k + y * t - x * t < l  else "Yes")
else:
    if r - l - x + 1 >= y:
        print("Yes")
    else:
        L = ((l - k + x) % y + y) % y
        if L != 0 and L + r - l - x < y:
            print("No")
            exit(0)
        for g in range(1, x + 1):
            if g + r - l - x >= y:
               break
            #a * x + b * y == g - l + k
            d, a, b = exgcd(x, y)
            if (g - l + k) % d:
                continue
            a = a * (g - l + k) // d
            a = (a % (y // d) + (y // d)) % (y // d)
            if a == 0:
                a += y // d
            if a <= t:
                print("No")
                exit(0)
        print("Yes")