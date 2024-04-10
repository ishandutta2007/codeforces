ID = input().split()
a = int(ID[0])
b = int(ID[1])
c = int(ID[2])
ans = []

for i in range(1, 82, 1):
    x = b * (i ** a) + c
    if (x > 0 and x < 1000000000):
        y = x
        z = 0
        while (y > 0):
            z += y % 10
            y //= 10
        if (z == i):
            ans.append(x)

print(len(ans))
for x in ans:
    print(x, end = ' ')