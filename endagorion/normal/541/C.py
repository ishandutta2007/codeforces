N = int(raw_input())
a = map(int, raw_input().split())
for i in xrange(N):
    a[i] -= 1

def pers(i):
    b = [-1] * N
    j = 0
    while b[i] == -1:
        b[i] = j
        i = a[i]
        j += 1
    return (b[i], j - b[i])

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a / gcd(a, b) * b

x = 1
l = 1
for i in xrange(N):
    pred, per = pers(i)
    x = lcm(x, per)
    if pred > l:
        l = pred
y = x
while y < l:
    y += x
print y