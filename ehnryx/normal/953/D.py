from sys import stdin, stdout

grid = []
for line in stdin:
	grid.append([x for x in line.strip()])

if grid[0][3] == '.':
	grid[0][3] = 'P'
elif grid[0][4] == '.':
	grid[0][4] = 'P'
elif grid[1][3] == '.':
	grid[1][3] = 'P'
elif grid[1][4] == '.':
	grid[1][4] = 'P'

elif grid[2][3] == '.':
	grid[2][3] = 'P'
elif grid[2][4] == '.':
	grid[2][4] = 'P'
elif grid[3][3] == '.':
	grid[3][3] = 'P'
elif grid[3][4] == '.':
	grid[3][4] = 'P'

elif grid[0][0] == '.':
	grid[0][0] = 'P'
elif grid[0][1] == '.':
	grid[0][1] = 'P'
elif grid[0][6] == '.':
	grid[0][6] = 'P'
elif grid[0][7] == '.':
	grid[0][7] = 'P'
elif grid[1][0] == '.':
	grid[1][0] = 'P'
elif grid[1][1] == '.':
	grid[1][1] = 'P'
elif grid[1][6] == '.':
	grid[1][6] = 'P'
elif grid[1][7] == '.':
	grid[1][7] = 'P'

elif grid[4][3] == '.':
	grid[4][3] = 'P'
elif grid[4][4] == '.':
	grid[4][4] = 'P'
elif grid[5][3] == '.':
	grid[5][3] = 'P'
elif grid[5][4] == '.':
	grid[5][4] = 'P'

elif grid[2][0] == '.':
	grid[2][0] = 'P'
elif grid[2][1] == '.':
	grid[2][1] = 'P'
elif grid[2][6] == '.':
	grid[2][6] = 'P'
elif grid[2][7] == '.':
	grid[2][7] = 'P'
elif grid[3][0] == '.':
	grid[3][0] = 'P'
elif grid[3][1] == '.':
	grid[3][1] = 'P'
elif grid[3][6] == '.':
	grid[3][6] = 'P'
elif grid[3][7] == '.':
	grid[3][7] = 'P'

elif grid[4][0] == '.':
	grid[4][0] = 'P'
elif grid[4][1] == '.':
	grid[4][1] = 'P'
elif grid[4][6] == '.':
	grid[4][6] = 'P'
elif grid[4][7] == '.':
	grid[4][7] = 'P'
elif grid[5][0] == '.':
	grid[5][0] = 'P'
elif grid[5][1] == '.':
	grid[5][1] = 'P'
elif grid[5][6] == '.':
	grid[5][6] = 'P'
elif grid[5][7] == '.':
	grid[5][7] = 'P'

for line in grid:
	stdout.write(''.join(line) + '\n')