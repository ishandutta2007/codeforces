for _ in range(int(input())):
   l,r,d=list(map(int, input().split()))
   print(d if d<l else (r//d+1)*d)