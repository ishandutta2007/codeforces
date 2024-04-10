n = int(input())
for i in range(n):
    a, b, c = map(int, input().split())
    print(min(a, b, (a + b + c) // 3))