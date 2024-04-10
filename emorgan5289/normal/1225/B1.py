t = int(input())
 
from collections import Counter
 
for _ in range(t):
    n, k, d = map(int, input().split())
    a = list(map(int, input().split()))
 
    s = Counter(a[:d])
    res = len(s)
    for i in range(d, len(a)):
        s[a[i - d]] -= 1
        s[a[i]] += 1
        if s[a[i-d]] == 0: del s[a[i-d]]
        res = min(res, len(s))
 
    print(res)