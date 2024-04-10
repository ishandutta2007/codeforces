k = int(input())
a = sorted(map(int, input().split()),reverse=True)
if sum(a) < k: print(-1)
else: print(min(i for i in range(13) if sum(a[:i]) >= k))