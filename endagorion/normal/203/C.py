N, d = [int(x) for x in raw_input().split()]
a, b = [int(x) for x in raw_input().split()]
C = []
for i in range(N):
    x, y = [int(x) for x in raw_input().split()]
    C.append([a * x + b * y, i + 1])

C.sort()
s = 0
ans = []
for i in range(N):
    s += C[i][0]
    if s <= d:
        ans.append(C[i][1])
    else:
        break

print len(ans)
for x in ans:
    print x,