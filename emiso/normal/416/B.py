m, n = [int(x) for x in input().split()]

time = [0 for i in range(n)]
answer = [0 for i in range(m)]

for i in range(m):
    t = [int(x) for x in input().split()]
    time[0] += t[0]
    for j in range(1, n):
        time[j] = max(time[j], time[j-1]) + t[j]
    answer[i] = time[n-1]

for i in range(m):
    print(answer[i], end = ' ')