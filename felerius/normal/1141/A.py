n, m = map(int, input().split(' '))
n2, n3, m2, m3 = [0] * 4
while n % 2 == 0:
    n //= 2
    n2 += 1
while n % 3 == 0:
    n //= 3
    n3 += 1
while m % 2 == 0:
    m //= 2
    m2 += 1
while m % 3 == 0:
    m //= 3
    m3 += 1
if n == m and m2 >= n2 and m3 >= n3:
    print(m2 + m3 - n2 - n3)
else:
    print(-1)