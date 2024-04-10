l=int(raw_input())
s=raw_input()
minlen=l+1
for i in range(2,l+1):
    if s[i-1]!='0':
        minlen=min(minlen,max(i-1,l-i+1))
minnum=-1
for i in range(2,l+1):
    if s[i-1]!='0' and max(i-1,l-i+1)==minlen:
        if minnum==-1: minnum=int(s[0:i-1])+int(s[i-1:l])
        else: minnum=min(minnum,int(s[0:i-1])+int(s[i-1:l]))
print minnum