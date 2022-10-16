turns = [(1, 2), (-1, 2), (1, -2), (-1, -2), (2, 1), (-2, 1), (2, -1), (-2, -1)]
board = [[True] * 8 for _ in range(8)]
lad = input()
xl, yl = ord(lad[0]) - ord('a'), int(lad[1]) - 1
board[xl][yl] = False
for i in range(8):
  board[xl][i] = False
  board[i][yl] = False
kon = input()
xk, yk = ord(kon[0]) - ord('a'), int(kon[1]) - 1
board[xk][yk] = False
for dx, dy in turns:
  if 0 <= xl + dx < 8 and 0 <= yl + dy < 8:
    board[xl + dx][yl + dy] = False
  if 0 <= xk + dx < 8 and 0 <= yk + dy < 8:
    board[xk + dx][yk + dy] = False
s = 0
for row in board:
  s += sum(row)
print(s)