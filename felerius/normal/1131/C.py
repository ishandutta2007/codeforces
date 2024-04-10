import itertools
n = int(input())
a = list(sorted(map(int, input().split())))
forw = (a[i] for i in range(0, len(a), 2))
backw = reversed([a[i] for i in range(1, len(a), 2)])
print(' '.join(str(i) for i in itertools.chain(forw, backw)))