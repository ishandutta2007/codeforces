n=int(input())
a=set()
while n not in a:
 a.add(n)
 n+=1
 while n%10==0: n//=10
print(len(a))