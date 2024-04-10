k, r = map(int, input().split())
print(min(i for i in range(1,11) if k * i % 10 in [r,0]))