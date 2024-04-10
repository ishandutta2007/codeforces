from collections import Counter

n = int(input())
cnt = Counter(map(int, input().split()))
print(max(cnt.items(), key=lambda x: x[1])[1], len(cnt))