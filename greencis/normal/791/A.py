a, b = map(int, input().split())
k = 0
while a <= b:
    k += 1
    a *= 3
    b *= 2
print(k)