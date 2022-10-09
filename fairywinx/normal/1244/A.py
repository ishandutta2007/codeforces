t = int(input())
for i in range(t):
    a, b, c, d, k = map(int, input().split())
    if ((a + c - 1) // c + (b + d - 1) // d > k):
        print(-1)
    else:
        print((a + c - 1) // c , (b + d - 1) // d)