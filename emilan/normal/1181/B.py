#!/usr/bin/env python3

n = int(input())
s = input()

ans = int(s)
for p in [n // 2 - 1, n // 2, n // 2 + 1]:
    for d in [-1, 1]:
        i = p
        while i < n and s[i] == "0": i += d
        if 0 < i < n: ans = min(ans, int(s[0:i]) + int(s[i:n]))

print(ans)