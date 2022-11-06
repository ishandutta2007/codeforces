a, b = map(int, input().split())
c = 0
while a != b:
    b, a = sorted((a, b))
    c += a // b
    a = a % b
    if a == 0:
        print(c)
        exit(0)
print(c + 1)