m=input().split()
n=(int)(m[0])
mod=(int)(m[1])
f=[0 for i in range(260005)]
s=[0 for i in range(260005)]
ans=[0 for i in range(505)]
cur=0
for i in range(0,260000):
	s[i]=1
 
for i in range(1,n+1):
	for j in range(0,cur+1):
		if j<i:
			f[j]=s[j]
		else :
			f[j]=s[j]-s[j-i]
			if f[j]<0:
				f[j]+=mod
	
	cur+=i
	s[0]=f[0]
	for j in range(1,cur+1):
		s[j]=s[j-1]+f[j]
		if s[j]>=mod:
			s[j]-=mod
	for j in range(0,cur+1):
		if j<i:
			f[j]=s[j]
		else :
			f[j]=s[j]-s[j-i]
			if f[j]<0:
				f[j]+=mod
	
	cur+=i
	s[0]=f[0]
	for j in range(1,cur+1):
		s[j]=s[j-1]+f[j]
		if s[j]>=mod:
			s[j]-=mod
	for j in range(1,i+1):
		if i*(i-1)//2+j<(i+1)*i:
			ans[i+1]=(ans[i+1]+(i-j+1)*(s[i*(i+1)]-s[i*(i-1)//2+j]+mod))%mod
	ans[i]=(ans[i]+i*ans[i-1])%mod
	
print(ans[n])