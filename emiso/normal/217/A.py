n = int(input())

p = []
for i in range(n):
    x, y = map(int, input().split())
    p.append((x, y))

visit = [False] * 101
def dfs(no):
    if visit[no]: return
    visit[no] = True
    for i in range(n):
        if p[no][0] == p[i][0] or p[no][1] == p[i][1]:
            dfs(i)

answer = 0
for no in range(n):
    if visit[no] == False:
        answer += 1
        dfs(no)

print(answer - 1)