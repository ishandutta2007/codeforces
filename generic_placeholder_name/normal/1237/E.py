import sys
input = sys.stdin.readline

n = int(input())
x = 1

while x <= n:
    if n - x in [0, 1]:
        print(1)
        sys.exit(0)
    else:
        x = x * 2 + 1 + (x & 1)
    
print(0)