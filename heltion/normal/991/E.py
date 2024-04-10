n = input()
cnt = [0] * 10
for d in n:
    cnt[int(d)] += 1
m = [0] * 10
ans = 0
def DFS(i : int):
    global ans
    if i == 10:
        pans = 1
        for j in range(sum(m)):
            pans *= j + 1
        for j in range(10):
            for k in range(m[j]):
                pans //= k + 1
        ans += pans
        if m[0]:
            pans = 1
            for j in range(1, sum(m)):
                pans *= j
            for j in range(10):
                for k in range(m[j] - (j == 0)):
                    pans //= k + 1
            ans -= pans
    elif cnt[i] == 0:
        DFS(i + 1)
    else:
        for j in range(0, cnt[i]):
            m[i] = j + 1
            DFS(i + 1)
DFS(0)
print(ans)