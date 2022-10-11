l, r, k = map(int, input().split())

x = 1
cnt = 0
while (x <= r):
    if (x >= l):
        cnt += 1
        print(x)
    x *= k

if (cnt == 0):
    print(-1)