tc=int(input())

for _ in range(tc):
	n=int(input())
	s=input().split("W")
	
	ok=True
	for x in s:
		if (len(x)==0): continue
		cnt1,cnt2=0,0
		for c in x:
			if (c=="B"): cnt1+=1
			else: cnt2+=1
			
		if (cnt1==0 or cnt2==0): ok=False
		
	if (ok): print("YES")
	else: print("NO")