A, B, C = [int(x) for x in input().split()]

for i in range(0, C + 1):
    if A * i > C:
        break
    if (C - A * i) % B == 0:
        print("Yes")
        exit(0)

print("No")