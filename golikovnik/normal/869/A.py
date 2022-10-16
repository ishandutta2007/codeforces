n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

from itertools import product

st = set((*a, *b))

npairs = sum((x ^ y) in st for x, y in product(a, b))
print('Koyomi' if npairs & 1 else 'Karen')