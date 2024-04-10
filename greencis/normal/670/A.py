n = int(input())
if n == 1:
    print("0 1")
else:
    print(n - n // 7 * 5 - min(5, n % 7), n - (n - 2) // 7 * 5 - min(5, (n - 2) % 7))