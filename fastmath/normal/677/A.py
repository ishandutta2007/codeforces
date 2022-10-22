n,h = map(int,input().split())
a = list(map(int,input().split()))
res = 0
for elem in a:
    if elem <= h:
        res += 1
    else:
        res += 2
print(res)