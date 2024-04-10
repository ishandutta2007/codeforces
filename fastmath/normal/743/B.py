n, k = map(int, input().split())

s = 0
while not(k % 2):
    s += 1
    k //= 2
    
print(s + 1)