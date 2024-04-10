m, k = map(int, input().split())
 
deg = [0] * 205
vals = set()
mp = {}
rev = {}
edges = []
c = 0
 
fr = []
for i in range(205):
    fr.append([0] * 205)
 
def check():
    changed = 0
    for v in range(c):
        for i in range(c):
            if (i != v and fr[i][v] == 0):
                cnt = 0
                for j in range(c):
                    if (j != v and j != i):
                        if (fr[j][v] == 2 and fr[j][i] == 2):
                            cnt += 1
                if (cnt * 100 >= k * deg[i]):
                    fr[i][v] = 1

for i in range(m):
    a, b = map(int, input().split())
    vals.add(a)
    vals.add(b)
    edges.append([a, b])
 
for x in vals:
    mp[x] = c
    rev[c] = x
    c += 1
 
for e in edges:
    a, b = mp[e[0]], mp[e[1]]
    deg[a] += 1
    deg[b] += 1
    fr[a][b] = 2
    fr[b][a] = 2
        
check()

lv = []
for x in mp.keys(): lv.append(x)
lv.sort()

for x in lv:
    fl = []
    for i in range(c):
        if (fr[mp[x]][i] == 1):
            fl.append(rev[i])
    print(str(x) + ": " + str(len(fl)), end = "")
    
    fl.sort()
    for i in range(len(fl)):
        print(" " + str(fl[i]), end = "")
    print()