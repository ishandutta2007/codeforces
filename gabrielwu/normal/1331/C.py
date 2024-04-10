x = int(input())
y = 0
if x% 2:
    y += 16
if (x>>1)%2:
    y += 2
if (x>>2)%2:
    y += 8
if (x>>3)%2:
    y += 4
if (x>>4)%2:
    y += 1
if (x>>5)%2:
    y += 32
print(y)