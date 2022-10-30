R=lambda:list(map(int,input().split()))
a,b,c,d=R()
e,f=R()
print('Yes'if abs(a-c)%e==0 and abs(b-d)%f==0 and abs(a-c)/e%2==abs(b-d)/f%2 else'No')