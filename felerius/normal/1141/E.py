import math
h, n = map(int, input().split(' '))
d = list(map(int, input().split(' ')))
round_diff = sum(d)
min_diff = 0
s = 0
for i, v in enumerate(d):
    s += v
    min_diff = min(s, min_diff)

round = 0
if round_diff >= 0:
    if h + min_diff > 0:
        print(-1)
        exit(0)
else:
    if h + min_diff > 0:
        round = int(math.ceil((h + min_diff) / -round_diff))

h += round_diff * round
for i, v in enumerate(d):
    h += v
    if h <= 0:
        print(round * n + i + 1)
        break