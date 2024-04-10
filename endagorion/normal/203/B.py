N, M = [int(x) for x in raw_input().split()]
S = []
for i in range(N + 2):
    S.append([0] * (N + 2))
for i in range(M):
    x, y = [int(x) - 1 for x in raw_input().split()]
    for xx in range(x, x + 3):
        for yy in range(y, y + 3):
            S[xx][yy] += 1
            if (S[xx][yy] == 9):
                print i + 1
                exit()
print -1