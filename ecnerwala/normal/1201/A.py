from collections import Counter
n,m = map(int,input().split())
s = [input() for _ in range(n)]
s = [*zip(*s)]
a = [*map(int,input().split())]
print(sum(x.most_common(1)[0][1] * y for x, y in zip(map(Counter, s), a)))