t = int(input())
for ti in range(t):
    line = input().split()
    a, b = int(line[0]), int(line[1])
    x = abs(a-b)
    acc = 0
    add = 0
    while(acc < x or (acc-x)%2 != 0):
        add += 1
        acc += add
    print(add)