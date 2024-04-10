import math
ntc=1
ntc=int(input())
for tc in range(1,ntc+1):
    n=int(input())
    ang=math.pi/(2*n)
    x=math.cos(ang)
    y=math.sin(ang)
    mx=x+y
    mn=x+y
    for i in range(2*n):
        ang+=math.pi/n
        x+=math.cos(ang)
        y+=math.sin(ang)
        mx=max(mx,x+y)
        mn=min(mn,x+y)
    print("%.12f"%((mx-mn)/(2**(1/2))))