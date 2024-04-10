a, b, c = sorted(int(x) for x in input().split())
print(max([0, c + 1 - a - b]))