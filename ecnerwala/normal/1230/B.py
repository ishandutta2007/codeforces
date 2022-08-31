n,k=map(int,input().split())
s=list(input())
for i in range(n):
 if not k:break
 c = str(int(not i and n>1))
 k -= s[i] != c
 s[i] = c
print(''.join(s))