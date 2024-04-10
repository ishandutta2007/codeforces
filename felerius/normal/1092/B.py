input()
stud = list(sorted(int(s) for s in input().split(' ')))

sum = 0
for i in range(len(stud) // 2):
    sum += (stud[2 * i + 1] - stud[2 * i])
print(sum)