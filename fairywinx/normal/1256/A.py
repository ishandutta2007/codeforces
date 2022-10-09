def gcd(a, b):
    if a == 0:
        return b
    else:
        return gcd(b % a, a)


t = int(input())
for u in range(t):
    a, b, n, s = map(int, input().split())
    if s % n > b:
        print('NO')
        continue
    b -= s % n
    if b + s % n + a * n >= s:
        print('YES')
        continue
    print('NO')