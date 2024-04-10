n, a, b, c = map(int, input().split())
if not n % 4:
    print(0)
elif n % 4 == 3:
    print(min(a, c + b, c * 3))
elif n % 4 == 2:
    print(min(2 * a, b, 2 * c))
elif n % 4 == 1:
    print(min(3 * a, b + a, c))