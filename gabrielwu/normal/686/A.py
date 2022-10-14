inp = input().split()

n, x = int(inp[0]), int(inp[1])

dis = 0

for i in range(n):
    q = input().split()
    if q[0] == '+':
        x += int(q[1])
    else:
        if x >= int(q[1]):
            x -= int(q[1])
        else:
            dis += 1

print(x, dis)