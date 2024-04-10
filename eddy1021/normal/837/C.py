R=lambda:list(map(int,input().split()))
n,a,b=R()
xy = [R() for _ in range(n)]
ans = 0
def f(xy1, xy2):
    tans = 0
    for _ in range(2):
        for __ in range(2):
            if (xy1[0]+xy2[0]<=a and max(xy1[1], xy2[1])<=b) or\
                (max(xy1[0], xy2[0])<=a and xy1[1]+xy2[1]<=b):
                tans=max(tans, xy1[0]*xy1[1] + xy2[0]*xy2[1])
            xy2[0], xy2[1] = xy2[1], xy2[0]
        xy1[0], xy1[1] = xy1[1], xy1[0]
    return tans
for i in range(n):
    for j in range(i+1,n):
        ans=max(ans, f(xy[i], xy[j]))
print(ans)