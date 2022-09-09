a,b=list(map(int,input().split()))
while a and b:
	if a>=2*b:
		a%=2*b
		continue
	if b>=2*a:
		b%=2*a
		continue
	break
print(a,b)