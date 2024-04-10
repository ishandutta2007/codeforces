R=lambda:list(map(int,input().split()))
r,d=R()
def ok():
  x,y,z=R()
  return 1 if (r-d+z)**2<=x*x+y*y<=(r-z)**2 else 0
print(sum(ok() for i in range(int(input()))))