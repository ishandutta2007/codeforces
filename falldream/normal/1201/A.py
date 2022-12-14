In=input().strip().split(' ')
n=int(In[0]);m=int(In[1])
b = [0 for i in range(n)]
C = [[0]*5 for i in range(m)]
num = [0 for i in range(n)]
for i in range(n):
    b[i]=input()
    for j in range(m):
        C[j][ord(b[i][j])-ord('A')]+=1
ans=0
score=input().strip().split(' ')
for i in range(m):
    mx=0
    for j in range(5):
        mx=max(mx,C[i][j])
    ans+=mx*int(score[i])
print(ans)