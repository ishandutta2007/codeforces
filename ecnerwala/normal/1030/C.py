n=int(input())
a=map(int,input())
s={0}
v=0
for i in a:
 v += i
 s.add(v)
print("NYOE S"[v==0 or any(v%i==0 and all(v//i*j in s for j in range(i)) for i in range(2,v+1))::2])