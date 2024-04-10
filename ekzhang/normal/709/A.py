n, b, d = map(int, raw_input().split())
a = map(int, raw_input().split())

c = 0
ans = 0
for x in a:
    if x > b: continue
    c += x
    if c > d:
        c = 0
        ans += 1
print ans