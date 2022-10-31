R=lambda:list(map(int,input().split()))
a,b=R()
x,y,z=R()
A=x+x+y
B=y+3*z
print(max(0,A-a)+max(0,B-b))