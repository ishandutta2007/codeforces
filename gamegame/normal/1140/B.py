def main():
	m=int(raw_input())
	s=raw_input()
	ans=m-1
	for i, c in enumerate(s):
		if c=='>' and ans>i:
			ans=i
		if c=='<' and ans>m-i-1:
			ans=m-i-1
	print(ans)
def solve():
	n=int(raw_input())
	for i in range(0,n):
		main()
if __name__ == '__main__':
    solve()