alpha='abcdefghijklmnopqrstuvwxyz'
s=input()
ans=[]
i=0
for c in s:
	if i<26 and c<=alpha[i]:
		ans.append(alpha[i])
		i+=1
	else:
		ans.append(c)
if(i==26):
	for c in ans:
		print(c,end='')
else:
	print(-1)