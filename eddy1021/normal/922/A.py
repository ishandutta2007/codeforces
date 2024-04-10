x,y=list(map(int,input().split()))
tot=(x+y)//2
print('Yes'if(x+y)%2==1 and 0<=(y-1)<=tot and x==(y-1)+2*(tot-y+1) and ((y == 1) == (tot == 0)) else'No')