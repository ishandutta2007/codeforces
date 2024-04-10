from sys import stdout


class Mock:
    def __init__(self, cap, a):
        self.a, self.cap = a, cap
        self.n, self.q = len(a), []

    def ask(self, i):
        result = self.a[i] in self.q
        self.q.append(self.a[i])
        if len(self.q) > self.cap:
            self.q = self.q[1:]
        return result

    def reset(self):
        self.q = []

    def out(self, result):
        print('!', result)


class IO:
    def __init__(self):
        self.n, self.cap = map(int, input().split())

    def ask(self, i):
        print('?', i + 1)
        stdout.flush()
        return input() == 'Y'

    def reset(self):
        print('R')
        stdout.flush()

    def out(self, result):
        print('!', result)


def solve(io):
    n, cap = io.n, io.cap
    size = cap + 1 >> 1
    count = n // size
    removed = [False] * n
    for d in range(1, count):
      for r in range(min(d, count - d)):
        for i in range(r, count, d):
          for j in range(i * size, (i + 1) * size):
            if not removed[j] and io.ask(j):
              removed[j] = True
      io.reset()
    return removed.count(False)


# io = Mock(2, [1, 4, 1, 3])
# io.out(solve(io))

# io = Mock(8, [1, 2, 3, 4, 5, 6, 6, 6])
# io.out(solve(io))

io = IO()
io.out(solve(io))