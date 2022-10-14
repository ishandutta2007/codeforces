n,k=map(int,input().split());a=[]
for i in range(n):
    for j in range(i+1,n):
        u,v,r=i,j,0
        while u^v:u//=k;v//=k;r+=1
        a.append(r)
print(max(a),*a)