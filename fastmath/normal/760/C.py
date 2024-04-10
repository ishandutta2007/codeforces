import sys
sys.setrecursionlimit(10 ** 9)


n = int(input())
p = list(map(int, input().split()))
b = list(map(int, input().split()))

used = [False] * n
comp = 0
for i in range(n):
    if not used[i]:
        u = i
        while True:
            used[u] = True
            v = p[u] - 1
            if not used[v]:
                u = v
            else:
                break
            
        comp += 1

if comp == 1:
    ans = 0
else:
    ans = comp

ed = 0
for i in range(n):
    if b[i]:
        ed += 1

if not ed % 2:
    ans += 1
    
print(ans)