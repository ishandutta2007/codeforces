ax,ay,bx,by,cx,cy=list(map(int,input().split()))
ax-=bx
ay-=by
cx-=bx
cy-=by
print('No'if ax*cy-ay*cx==0 or ax**2+ay**2!=cx**2+cy**2 else'Yes')