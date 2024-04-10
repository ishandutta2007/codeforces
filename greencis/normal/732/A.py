k, x = map(int, input().split())
y = 0
while True:
    if y % k == 0 and y:
        print(y // k)
        break
    if (y + x) % k == 0:
        print((y + x) // k)
        break
    y += 10