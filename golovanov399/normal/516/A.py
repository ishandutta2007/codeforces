n = int(raw_input())
s = raw_input()

a = [0 for i in range(10)]
for c in s:
    x = int(c)
    if (x == 4):
        a[2] += 2
        a[3] += 1
    elif (x == 8):
        a[7] += 1
        a[2] += 3
    elif (x == 9):
        a[7] += 1
        a[3] += 2
        a[2] += 1
    elif (x == 6):
        a[5] += 1
        a[3] += 1
    elif (x > 1):
        a[x] += 1

ans = ""
for i in range(9, -1, -1):
    ans += str(i) * a[i]

print ans