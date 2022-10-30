R=lambda:list(map(int,input().split()))
input()
a=sum(R())
for i in range(int(input())):
  c,d=R()
  if c<=a<=d:
    print(a)
    exit(0)
  elif a<c:
    print(c)
    exit(0)
print(-1)