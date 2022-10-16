from collections import Counter

n = int(input())
cnt = Counter()
arr = [int(i) for i in input().split()]
for i in arr:
    cnt[i] += 1
ans = sum(i[1] for i in cnt.items())
left = 0
for i, el in enumerate(sorted(cnt.items())):
    num, val = el
    if i == 0:
        left = val
        continue
    elif val >= left:
        ans -= left
        left = 0
        left += val
    else:
        left -= val
        ans -= val
        left += val
print(ans)