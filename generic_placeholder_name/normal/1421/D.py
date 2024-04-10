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

#such incredible bullshit
#i can't even

def solve_case():
    y, x = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]
    
    if x == 0 and y == 0:
        print(0)
        return
    
    d1 = 0
    if x > 0:
        d1 += x * c[1]
    else:
        d1 -= x * c[4]
    if y > 0:
        d1 += y * c[5]
    else:
        d1 -= y * c[2]
    
    d2 = 0
    if x > 0:
        d2 += x * c[0]
    else:
        d2 -= x * c[3]
    if x > y:
        d2 += (x - y) * c[2]
    else:
        d2 += (y - x) * c[5]
    
    d3 = 0
    if y > 0:
        d3 += y * c[0]
    else:
        d3 -= y * c[3]
    if y > x:
        d3 += (y - x) * c[4]
    else:
        d3 += (x - y) * c[1]
    
    print(min(d1, d2, d3))

def main():
    for _ in range(int(input())):
        solve_case()
    
main()