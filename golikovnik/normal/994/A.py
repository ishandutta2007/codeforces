# your code goes here
n, m = map(int, input().split())

a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

res = [x for x in a if x in b]

print(*res)