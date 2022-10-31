for _ in range(int(input())):
  n,a,b=list(map(int, input().split()))
  print(n//2*min(a+a,b)+n%2*a)