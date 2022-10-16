n = int(input())
r = n % 10
low = n - r
high = n - r + 10
if n - low <= high - n:
    print(low)
else:
    print(high)