import os
import sys
from io import BytesIO, IOBase
# region fastio
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

def ask(l1, r1, l2, r2):
    print('?', r1 - l1 + 1, r2 - l2 + 1)
    print(*list(range(l1, r1 + 1)))
    print(*list(range(l2, r2 + 1)))
    print(end = '', flush = True)
    return int(input())
    
def solve_case():
    n = int(input())
    ans = []
    for i in range(2, n + 1):
        if ask(1, i - 1, i, i) != 0:
            for j in range(i + 1, n + 1):
                if ask(i, i, j, j) == 0:
                    ans.append(j)
            l, r = 1, i - 1
            while l < r:
                m = (l + r) >> 1
                if ask(l, m, i, i) != 0:
                    r = m
                else:
                    l = m + 1
            for j in range(1, i):
                if j != l:
                    ans.append(j)
            print('!', len(ans), *ans, flush = True)
            return

def main():
    for _ in range(int(input())):
        solve_case()

main()