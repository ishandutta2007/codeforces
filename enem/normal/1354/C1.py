import math
ntc=1
ntc=int(input())
for tc in range(1,ntc+1):
    n=int(input())
    ans=0
    for i in range(n):
        ans+=math.sin(i*math.pi/n)
    print("%.12f"%ans)