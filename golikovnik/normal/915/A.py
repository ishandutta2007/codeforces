n, k = map(int, input().split())
mn = 111
for x in input().split():
    x = int(x)
    if not k % x:
        mn = min(mn, k // x)
print(mn)