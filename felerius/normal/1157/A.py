n = int(input())
s = set()
while n not in s:
    s.add(n)
    n += 1
    while n % 10 == 0:
        n //= 10

print(len(s))