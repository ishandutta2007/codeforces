
def solve(s):
	m = {3: -1e9, 1: -1e9, 2  : -1e9};
	ans = 1e9;
	for i in range(len(s)):
		m[int(s[i])] = i;
		x = min(m.values());
		ans = min(ans, i-x+1);
	if ans > len(s) :
		print(0);
	else :
		print(ans);


for _ in range(int(input())) :
	s = input()
	solve(s);