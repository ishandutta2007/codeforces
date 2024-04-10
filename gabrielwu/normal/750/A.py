inp = input().split()
n, k = int(inp[0]), int(inp[1])

x = 240-k
c = 0
tot = 0
while tot <= x:
    c += 1
    tot += 5*c
print(min(n, c-1))