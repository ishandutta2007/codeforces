n=int(input())
s=n*['o']
i,j=0,1
while i+j<=n:
  i,j=j,i+j
  s[j-1]='O'
print(''.join(s))