v = int(input())
s = [1200, 1400, 1600, 1000, 2100, 2300, 2400, 2600, 3000]
print(next(a for a in s if a > v))