x=int(input())
h,m=list(map(int,input().split()))
def ok(mm):
  while mm<0: mm+=1440
  hh=mm//60
  mm=mm%60
  return hh%10==7 or hh//10==7 or mm%10==7 or mm//10==7
for y in range(999):
  if ok(h*60+m-y*x):
    print(y)
    exit(0)