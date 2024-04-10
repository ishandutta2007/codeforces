n = int(input())
s = [ord(x) - ord('0') for x in input()]
t = [ord(x) - ord('0') for x in input()]
if sum(s) != sum(t):
    print(-1)
else:
    cur, mx, mn = 0, 0, 0
    for i in range(n):
        cur += s[i] - t[i]
        mx = max(mx, cur)
        mn = min(mn, cur)
    print(mx - mn)