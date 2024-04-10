# coding = utf-8

maxN = int(1e5 + 3)
eps = 1e-10
x = [0 for k in range(maxN)]
y = [0 for k in range(maxN)]
n = 0
r = 0
d = 0
def read():
    global x,n,r,d
    n,r = (int(k) for k in input().split())
    r = float(r)
    d = 2*r
    x = [float(k) for k in input().split()]
def doit():
    for i in range(n):
        this_y = r
        for j in range(i):
            dx = abs(x[i]-x[j])
            if dx < d+eps:
                new_y = y[j] + (d**2-dx**2)**0.5
                if new_y > this_y:
                    this_y = new_y
        y[i] = this_y
def main():
    read()
    doit()
    print(*y[:n])
main()