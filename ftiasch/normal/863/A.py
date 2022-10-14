n = int(input())
while n % 10 == 0:
    n //= 10
n = str(n)
print(n == n[::-1] and 'YES' or 'NO')