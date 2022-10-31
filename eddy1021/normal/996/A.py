n=int(input())
a=0
for i in[100,20,10,5,1]:
  a+=n//i
  n%=i
print(a)