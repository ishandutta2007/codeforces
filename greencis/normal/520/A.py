input()
u=[0]*26
s=input().lower()
ans=0
for x in s:
 num=ord(x)-97
 if u[num] == 0:
  ans+=1
  u[num]=1
print("YNEOS"[ans<26::2])