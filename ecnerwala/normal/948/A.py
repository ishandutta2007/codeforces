r, c = map(int, input().split())
g = [input() for _ in range(r)]
good = True
for i in range(r):
    for j in range(c):
        if i > 0 and {g[i][j], g[i-1][j]} == {'S','W'}:
             good = False
        if j > 0 and {g[i][j], g[i][j-1]} == {'S', 'W'}:
             good = False
if good:
    print("Yes")
    print('\n'.join(''.join('D' if v == '.' else v for v in row) for row in g))
else:
    print("No")