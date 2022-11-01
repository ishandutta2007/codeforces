a=[0]+map(int, raw_input().split())
print sum(map(a.__getitem__, map(int, raw_input())))