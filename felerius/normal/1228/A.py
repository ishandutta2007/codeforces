l, r = map(int, input().split())
for i in range(l, r + 1):
    if len(set(str(i))) == len(str(i)):
        print(i)
        exit(0)
print(-1)