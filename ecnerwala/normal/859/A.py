n=int(input())
a = map(int, input().split())
res = max(0, max(a) - 25)
print(res)