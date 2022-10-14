for _ in range(int(input())):
    a, b, c = [int(x) for x in input().split()]
    x = 1 if a < c else -1
    y = b if a * b > c else -1
    print("{} {}".format(x, y))