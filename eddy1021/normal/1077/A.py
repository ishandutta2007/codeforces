for i in range(int(input())):
  a,b,k=list(map(int, input().split()))
  print((a-b)*(k//2)+k%2*a)