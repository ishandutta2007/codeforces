import itertools

TC=int(input())

m={"A":0,"N":1,"O":2,"T":3}
st="ANOT"

for _ in range(TC):
	s=input()
	arr=[]
	
	for ch in s:
		arr.append(m[ch])
	
	cnt=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
	cnt1=[0,0,0,0]
	
	for i in arr:
		for j in range(4):
			cnt[j][i]+=cnt1[j]
		cnt1[i]+=1
	
	val=-1
	best=[]
	
	for perm in itertools.permutations([0,1,2,3]):
		curr=0
		for i in range(4):
			for j in range(i+1,4):
				curr+=cnt[perm[j]][perm[i]]	
		
		if (curr>val):
			val=curr
			best=perm
			
	
	for i in range(4):
		for j in range(cnt1[best[i]]): print(st[best[i]],end="")
	
	print()