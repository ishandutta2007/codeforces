n = int(input())
if n < 3:
	print(-1)
else:
	ans = [[-1 for _ in range(n)] for _ in range(n)]
	b = n*n-9
	ans[0][0] = b+9
	ans[0][1] = b+6
	ans[0][2] = b+7
	ans[1][0] = b+5
	ans[1][1] = b+3
	ans[1][2] = b+8
	ans[2][0] = b+1
	ans[2][1] = b+2
	ans[2][2] = b+4
	for i in range(3, n):
		if i&1:
			for j in range(i+1):
				ans[i][j] = n*n-i*i-j
			for j in range(i-1, -1, -1):
				ans[j][i] = n*n-(i+1)*(i+1)+j+1
		else:
			for j in range(i+1):
				ans[j][i] = n*n-i*i-j
			for j in range(i-1, -1, -1):
				ans[i][j] = n*n-(i+1)*(i+1)+j+1
	for x in ans:
		print(*x)