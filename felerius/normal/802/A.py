n, k = map(int, input().split())
a = list(map(int, input().split()))
inventory = set()
bought = 0
for i in range(n):
    if a[i] not in inventory:
        if len(inventory) == k:
            farthest_time = 0
            farthest = 0
            for v in inventory:
                try:
                    far = a.index(v, i + 1)
                    if far > farthest_time:
                        farthest_time = far
                        farthest = v
                except ValueError:
                    farthest_time = 10000
                    farthest = v
            inventory.remove(farthest)
        inventory.add(a[i])
        bought += 1

print(bought)