n = int(input())
a = [int(x) for x in input().split()]

print(*[x - ((x ^ 1) & 1) for x in a])