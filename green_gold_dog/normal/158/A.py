a = list(map(lambda x: int(x), input().split()))
summ = 0
b = list(map(lambda x: int(x), input().split()))
for i in b:
    if (i >= b[a[1]-1]) and (i > 0):
        summ += 1
print(summ)