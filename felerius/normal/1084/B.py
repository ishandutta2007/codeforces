import math

n, s = (int(s2) for s2 in input().split(' '))
kegs = [int(s2) for s2 in input().split(' ')]

min_keg = min(kegs)
overflow = sum(keg - min_keg for keg in kegs)
if s <= overflow:
    print(min_keg)
else:
    remaining = s - overflow
    n = int(math.ceil(remaining / len(kegs)))
    if n > min_keg:
        print(-1)
    else:
        print(min_keg - n)