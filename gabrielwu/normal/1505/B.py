n = input().strip()
while len(n) > 1:
    x = 0
    for c in n:
        x += int(c)
    n = str(x)
print(n)