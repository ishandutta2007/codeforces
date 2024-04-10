t = int(input())
for ti in range(t):
    inp = input().split()
    a, b, x, y = int(inp[0]), int(inp[1]), int(inp[2]), int(inp[3])
    
    print(max(b*x, b*(a-x-1), a*y, a*(b-y-1)))