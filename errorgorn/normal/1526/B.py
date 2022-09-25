tc=int(input())

for _ in range(tc):
	n=int(input())
	
	can=False
	for i in range(20):
		if (n%11==0): can=True
		
		n-=111
		if (n<0):
			break
	
	if (can): print("yes")
	else: print("no")