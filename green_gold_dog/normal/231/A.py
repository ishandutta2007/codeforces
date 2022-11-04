a = int(input())
summ = 0
for i in range(a):
    inp = list(map(lambda x: int(x), input().split()))
    sum_now = inp[0]+inp[1]+inp[2]
    if sum_now > 1:
        summ += 1
print(summ)