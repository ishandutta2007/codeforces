l, r, k = map(int, input().split())
k2 = 1
found = False
while k2 <= r:
    if k2 >= l:
        found = True
        print(k2, end=' ')
    k2 *= k
if found:
    print()
else:
    print(-1)