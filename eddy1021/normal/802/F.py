for i in range(int(input())):
  a=list(map(int,input().split()))
  mx=max(list(map(abs,a)))
  std=(sum(list(map(lambda x:x*x,a)))/len(a))**0.5
  print('poisson'if mx/std>2 else'uniform')