for i in range(int(input())):
  n,v,l,r=list(map(int, input().split()))
  print(n//v-r//v+(l-1)//v)