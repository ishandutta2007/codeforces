inp = input().split()
a = int(inp[0])
b = int(inp[1])
x = min(a, b)

ans = 1
for i in range(1, x+1):
    ans *= i
    
print(ans)