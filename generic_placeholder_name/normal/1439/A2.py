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
 
def main():
    for _ in range(int(input())):
        n, m = [int(x) for x in input().split()]
        t = [[int(x) for x in input()] for i in range(n)]
        ans = []
        
        def op(a, b, c):
            t[a[0]][a[1]] ^= 1
            t[b[0]][b[1]] ^= 1
            t[c[0]][c[1]] ^= 1
            ans.append([a[0]+1, a[1]+1, b[0]+1, b[1]+1, c[0]+1, c[1]+1])
        
        for i in range(n-1, 1, -1):
            for j in range(m):
                if t[i][j]:
                    if j + 1 < m:
                        op((i, j), (i-1, j), (i-1, j+1))
                    else:
                        op((i, j), (i-1, j), (i-1, j-1))
                        
        for j in range(m-1, 1, -1):
            for i in range(2):
                if t[i][j]:
                    op((i, j), (0, j-1), (1, j-1))
        
        for i in range(2):
            for j in range(2):
                tot = t[0][0] + t[0][1] + t[1][0] + t[1][1]
                if (tot + t[i][j]) % 2:
                    op((1-i, j), (1-i, 1-j), (i, 1-j))
                    
        print(len(ans))
        for op in ans:
            print(*op)
 
main()