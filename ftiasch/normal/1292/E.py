from collections import defaultdict
from itertools import product
from sys import stdout


def find(s, t):
    return tuple(i for i in range(len(s) - len(t) + 1) if s[i:i+len(t)] == t)


class Mock:
    def __init__(self, s):
        self.s = s
        self.cost = 0.0

    @property
    def n(self):
        return len(self.s)

    def ask(self, t):
        self.cost += 1.0 / len(t) ** 2
        return find(self.s, t)

    def out(self, t):
        assert(self.s == t)
        assert(self.cost <= 7.0 / 5.0)
        print('OK')


class IO:
    def __init__(self):
        self.n = int(input())

    def ask(self, t):
        stdout.write('? ' + t + '\n')
        stdout.flush()
        return tuple(int(i) - 1 for i in input().split()[1:])

    def out(self, t):
        stdout.write('! ' + t + '\n')
        stdout.flush()
        input()


PATTERNS = 'CC OC HC HO HH'.split()

candidates_map = defaultdict(lambda: [])
for iterator in product(*['CHO'] * 4):
    s = ''.join(iterator)
    candidates_map[tuple(find(s, p)
                         for p in PATTERNS[:4])].append(s)

bads = ['CHHH', 'COHH', 'COOH', 'COOO', 'HHHH', 'OHHH', 'OOHH', 'OOOH', 'OOOO']
bad_candidates_map = defaultdict(lambda: [])
for s in bads:
    bad_candidates_map[(find(s, 'OOO'), find(s, 'HHH'))].append(s)


def solve(io):
    n = io.n
    if n == 4:
        features = tuple(
            io.ask(p)
            for p in PATTERNS[:4]
        )
        candidates = candidates_map[features]
        if len(candidates) > 7:
            candidates = bad_candidates_map[(io.ask('OOO'), io.ask('HHH'))]
        for c in candidates[:-1]:
            if 0 in io.ask(c):
                return io.out(c)
        io.out(candidates[-1])
    else:
        r = ['?'] * n
        for p in PATTERNS:
            for i in io.ask(p):
                r[i], r[i + 1] = p
        for i in range(1, n - 1):
            if r[i] == '?':
                r[i] = 'O'
        if r[0] == '?':
            r[0] = 'C' if 0 in io.ask('C' + ''.join(r[1:-1])) else 'O'
        if r[-1] == '?':
            r[-1] = 'H' if 0 in io.ask(''.join(r[:-1]) + 'H') else 'O'
        io.out(''.join(r))

for _ in range(int(input())):
    solve(IO())