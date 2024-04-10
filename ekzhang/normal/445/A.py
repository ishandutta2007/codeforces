def other(color):
    if color == 'B':
        return 'W'
    if color == 'W':
        return 'B'
    return None

def getAns(board):
    tovisit = []

    while True:
        x = 0
        y = 0
        while board[y][x] != '.':
            x += 1
            if x >= M:
                x = 0
                y += 1
            if y >= N:
                return '\n'.join(map(lambda x: ''.join(x), board))

        tovisit.append([x, y])
        board[y][x] = 'B' # anything
        # now, get good neighbors of (x, y) and set them to the opposite until visited runs out
        while tovisit:
            coords = tovisit.pop(0)
            c = board[coords[1]][coords[0]]
            neighbors = []
            if coords[0] < len(board[0]) - 1:
                neighbors.append([coords[0] + 1, coords[1]])
            if coords[0] > 0:
                neighbors.append([coords[0] - 1, coords[1]])
            if coords[1] < len(board) - 1:
                neighbors.append([coords[0], coords[1] + 1])
            if coords[1] > 0:
                neighbors.append([coords[0], coords[1] - 1])

            for i in neighbors:
                if board[i[1]][i[0]] == '.':
                    board[i[1]][i[0]] = other(c)
                    tovisit.append(i)
    

N, M = map(int, raw_input().split())
board = [list(raw_input()) for _ in xrange(N)]
print getAns(board)