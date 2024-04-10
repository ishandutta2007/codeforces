n, h = map(int, input().split())
a = list(map(int, input().split()))
print(n + sum(i > h for i in a))