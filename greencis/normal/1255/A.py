r=input
for _ in [0]*int(r()):
 a,b=map(int,r().split())
 c=abs(b-a)
 d=c//5
 c%=5
 d+=c//2
 c%=2
 d+=c
 print(d)