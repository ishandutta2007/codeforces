print('YES')
for i in range(int(input())):
    x, y, a, b = [int(x) for x in input().split()]
    print(x % 2 + y % 2 * 2 + 1)