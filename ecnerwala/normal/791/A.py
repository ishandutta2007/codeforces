a,b = map(int, input().split())
print(next(i for i in range(10000000000) if 3 ** i * a > 2 ** i * b))