def solve(a, b):
    if a == b:
        return "01" * a
    if a > b:
        return "0" * (a - b) + "10" * b
    return "1" * (b - a) + "01" * a


for _ in range(int(input())):
    a, b = map(int, input().split())
    print(solve(a, b))