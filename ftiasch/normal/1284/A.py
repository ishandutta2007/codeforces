n, m = map(int, input().split())
a = input().split()
b = input().split()
for _ in range(int(input())):
    x = int(input()) - 1
    print(a[x % len(a)] + b[x % len(b)])