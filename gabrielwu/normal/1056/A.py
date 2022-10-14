n = int(input())

def intersect(a, b):
    x = []
    for i in a:
        if i in b:
            x.append(i)
    return x
    

things = [input().split()[1:] for i in range(n)]
ans = things[0]
for i in range(1, n):
    ans = intersect(ans, things[i])

print(" ".join(ans))