import itertools
n, k = (int(s) for s in input().split())
a = [int(s) for s in input().split()]
s = input()
dmg = 0
for _, g in itertools.groupby(enumerate(s), key=lambda t: t[1]):
    dmgs = list(sorted(a[i] for i, _ in g))
    dmg += sum(dmgs[-k:])
print(dmg)