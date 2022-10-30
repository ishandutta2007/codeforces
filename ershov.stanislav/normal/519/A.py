import sys

#sys.stdin = open('in.txt', 'rt')

w = 0
d = {'Q': 9, 'R': 5, 'B': 3, 'N': 3, 'P': 1, 'K': 0,
     'q': -9, 'r': -5, 'b': -3, 'n': -3, 'p': -1, 'k': 0, '.': 0}

for i in range(8):
    s = input().strip()
    for c in s:
        w += d[c]

if w > 0:
    print('White')
elif w == 0:
    print('Draw')
else:
    print('Black')