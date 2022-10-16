

def main():
	ok = True
	n, m = map(int, input().split())
	maxi = 0
	for _ in range(n):
		a, b = map(int, input().split())
		if a > maxi:
			ok = False
			break
		maxi = max(maxi, b)
	if maxi < m:
		ok = False
	print("YES" if ok else "NO") 


if __name__ == '__main__':
	main()