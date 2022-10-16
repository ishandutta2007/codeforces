n = int(input())
friends = {}
for _ in range(n):
    data = input().split()
    name = data[0]
    numbers = set(data[2:])
    if name in friends:
        friends[name].update(numbers)
    else:
        friends[name] = numbers
print(len(friends))
for friend, numbers in friends.items():
    used = numbers.copy()
    for x in numbers:
        for y in numbers:
            if x == y:
                continue
            if x not in used or y not in used:
                continue
            if y.endswith(x):
                used.remove(x)
    print(friend, len(used), *used)