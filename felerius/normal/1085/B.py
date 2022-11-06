n, k = (int(s) for s in input().split(' '))
max_mod = min(n, k - 1)
min_x = 99999999999999999
for i in range(1, max_mod + 1):
    if n % i == 0:
        div = n // i
        x = div * k + i
        if x < min_x:
            min_x = x
print(min_x)