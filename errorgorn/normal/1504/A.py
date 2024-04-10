tc=int(input())

for i in range(tc):
	s=input()
	
	t=s+'a'
	w='a'+s
	if (t!=t[::-1]):
		print("YES")
		print(t)
	elif (w!=w[::-1]):
		print("YES")
		print(w)
	else:
		print("NO")