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

def solve_case():
    a = [int(x) for x in input()]
    b = [int(x) for x in input()]
    n = len(a)
    
    a_rev = []
    b_rev = []
    
    def rev_a(x):
        if not x:
            return
        nonlocal a
        a = a[:x][::-1] + a[x:]
        a_rev.append(x)

    def rev_b(x):
        if not x:
            return
        nonlocal b
        b = b[:x][::-1] + b[x:]
        b_rev.append(x)

    def answer():
        #cleaning up
        nonlocal a_rev
        nonlocal b_rev
        b_rev.reverse()
        a_rev += b_rev
        while True:
            final = []
            i = 0
            repl = False
            while i < len(a_rev):
                if i < len(a_rev) - 1 and a_rev[i] == a_rev[i + 1]:
                    repl = True
                    i += 2
                else:
                    final.append(a_rev[i])
                    i += 1
            a_rev = final
            if not repl:
                break
        print(len(a_rev))
        print(*a_rev)
    
    a_occ = [[0, 0], [0, 0]]
    b_occ = [[0, 0], [0, 0]]
    
    for i in range(0, n, 2):
        a_occ[a[i]][a[i + 1]] += 1

    for i in range(0, n, 2):
        b_occ[b[i]][b[i + 1]] += 1
    
    if a_occ[0][0] != b_occ[0][0] or a_occ[1][1] != b_occ[1][1]:
        print(-1)
        return
    
    balanced = a_occ[0][1] == b_occ[1][0]
    if not balanced:
        zero, one = 0, 0
        for i in range(0, n, 2):
            if a[i] + a[i + 1] == 1:
                zero, one = zero + a[i], one + a[i + 1]
                if zero + (a_occ[0][1] - one) == b_occ[1][0]:
                    balanced = True
                    rev_a(i + 2)
                    break
    
    if not balanced:
        zero, one = 0, 0
        for i in range(0, n, 2):
            if b[i] + b[i + 1] == 1:
                zero, one = zero + b[i], one + b[i + 1]
                if zero + (b_occ[0][1] - one) == a_occ[1][0]:
                    balanced = True
                    rev_b(i + 2)
                    break
 
    for i in range(0, n, 2):
        for j in range(i, n, 2):
            if a[j] == b[n - i - 1] and a[j + 1] == b[n - i - 2]:
                rev_a(j)
                rev_a(j + 2)
                break
    
    answer()

def main():
    for _ in range(int(input())):
        solve_case()
            
main()