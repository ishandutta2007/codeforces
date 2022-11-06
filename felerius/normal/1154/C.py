foods = list(map(int, input().split())) 

types = [0, 1, 2, 0, 2, 1, 0]
max_days = 0
for day in range(7):
    days = 0
    foods2 = foods[:]
    for i in range(day, 7):
        if foods2[types[i]] == 0:
            break
        foods2[types[i]] -= 1
        days += 1
    weeks = min(foods2[0] // 3, foods2[1] // 2, foods2[2] // 2)
    days += 7 * weeks
    foods2[0] -= 3 * weeks
    foods2[1] -= 2 * weeks
    foods2[2] -= 2 * weeks
    for i in range(7):
        if foods2[types[i]] == 0:
            break
        foods2[types[i]] -= 1
        days += 1
    max_days = max(max_days, days)

print(max_days)