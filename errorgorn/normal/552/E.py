s=input()

idx=[-1]

for i in range(len(s)):
	if (s[i]=='*'): idx.append(i)

idx.append(len(s))

ans=0
for i in range(len(idx)):
	for j in range(i+1,len(idx)):
		ans=max(ans,eval(s[:idx[i]+1]+"("+s[idx[i]+1:idx[j]]+")"+s[idx[j]:]))
print(ans)