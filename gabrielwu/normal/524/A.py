inp = input().split()
m, K = int(inp[0]), int(inp[1])
 
d = {}
for i in range(m):
    inp = input().split()
    a, b = int(inp[0]), int(inp[1])
    if a in d.keys():
        d[a].append(b)
    else:
        d[a] = [b]
    if b in d.keys():
        d[b].append(a)
    else:
        d[b] = [a]
 
a = {}
for i in d.keys():
    ans = []
    for j in d.keys():
        c = 0
        for k in d[j]:
            if k in d[i]:
                c += 1
        if c / len(d[i])*100 + 1e-8 >= K and j != i and j not in d[i]:
            ans.append(j)
    a[i] = ans
 
for i in sorted(d.keys()):
    print(str(i)+ ":", len(a[i]), " ".join([str(x) for x in sorted(a[i])]))