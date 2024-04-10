
def solve(a,b,c,d):
	ans = b
	a -= b
	if a <= 0:
		print(ans);
		return;
	if d >= c :
		print(-1);
		return;
	r = (a+(c-d-1))//(c-d);
	print(r*c+ans);
	


for _ in range(int(input())) :
	a,b,c,d = map(int, input().split())
	solve(a,b,c,d);