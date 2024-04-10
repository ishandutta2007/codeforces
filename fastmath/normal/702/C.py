def lower_bownd(key):
    left = -1
    right = m
    while left < right - 1:
        middle = (left + right) // 2
        if b[middle] <= key:
            left = middle
        else:
            right = middle
    
    if right < m:
        r = b[right] - key
    else:
        r = INF
    if left > -1:
        l = key - b[left]
    else:
        l = INF
    return min(l, r)


n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = [0] * n
INF = 10 ** 10
for i in range(n):
    ans[i] = lower_bownd(a[i])
print(max(ans))