import sys
B, A=999, 666
M=(1+B)>>1
R=lambda:list(map(int, input().split()))
kx, ky=R()
p=[R() for i in range(A)]
def go(x, y):
  sys.stdout.write('{} {}\n'.format(x, y))
  sys.stdout.flush()
  a, b, c=R()
  if a==-1: exit(0)
  p[a-1]=[b, c]
  global kx, ky
  kx, ky=x, y
dx=[-1,-1,-1,0,1,1,1,0]
dy=[-1,0,1,1,1,0,-1,-1]
def dst(sx, sy, tx, ty): return max(abs(sx-tx), abs(sy-ty))
def ok(xx, yy): return 1<=xx<=B and 1<=yy<=B and [xx, yy] not in p
def move_to(gx, gy):
  global kx, ky
  while kx!=gx or ky!=gy:
    nx, ny, nd=kx, ky, B+B+B
    for dd in range(8):
      nxtx, nxty=kx+dx[dd], ky+dy[dd]
      if not ok(nxtx, nxty): continue
      if dst(nxtx, nxty, gx, gy)<=nd:
        nx, ny, nd=nxtx, nxty, dst(nxtx, nxty, gx, gy)
    go(nx, ny)
def cnt(lx, ly, rx, ry):
  return sum(1 for pp in p if lx<=pp[0]<=rx and ly<=pp[1]<=ry)
move_to(M, M)
fx, fy, fc=B, B, cnt(1, 1, M, M)
if cnt(1, M, M, B)<fc: fx, fy, fc=B, 1, cnt(1, M, M, B)
if cnt(M, 1, B, M)<fc: fx, fy, fc=1, B, cnt(M, 1, B, M)
if cnt(M, M, B, B)<fc: fx, fy, fc=1, 1, cnt(M, M, B, B)
move_to(fx, fy)