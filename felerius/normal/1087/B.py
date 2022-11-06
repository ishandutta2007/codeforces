n, k = (int(s) for s in input().split(' '))
max_mod = min(n, k - 1)
min_x = 9999999999999999999
for mod in range(1, max_mod + 1):
    if n % mod == 0:
        div = n // mod
        x = k * div + mod
        if x < min_x:
            min_x = x
print(min_x)