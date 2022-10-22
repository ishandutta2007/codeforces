n, c, d = map(int, input().split())

inf = 10 ** 9
a = [0] * n
sc = []
sd = []
for i in range(n):
    b, p, t = input().split()
    b = int(b)
    p = int(p)
    
    a[i] = [b, p, t]
    
    if t == 'C':
        sc.append([p, b])
    else:
        sd.append([p, b])
        
    
maxc = -inf
maxd = -inf
for i in range(n):
    if a[i][2] == 'C' and a[i][1] <= c:
        maxc = max(maxc, a[i][0])
        
    if a[i][2] == 'D' and a[i][1] <= d:
        maxd = max(maxd, a[i][0])    
        
ans1 = maxc + maxd

sc.sort()
scpref = [0] * (len(sc) + 1)
scpref[0] = -inf
for i in range(len(sc)):
    scpref[i + 1] = max(scpref[i], sc[i][1])

ans2 = -inf
for i in range(len(sc)):
    l = -1
    r = i
    while l < r - 1:
        m = (l + r) // 2
        if sc[m][0] <= c - sc[i][0]:
            l = m
        else:
            r = m
            
    ans2 = max(ans2, sc[i][1] + scpref[l + 1])
    
    
sd.sort()
sdpref = [0] * (len(sd) + 1)
sdpref[0] = -inf
for i in range(len(sd)):
    sdpref[i + 1] = max(sdpref[i], sd[i][1])

ans3 = -inf
for i in range(len(sd)):
    l = -1
    r = i
    while l < r - 1:
        m = (l + r) // 2
        if sd[m][0] <= d - sd[i][0]:
            l = m
        else:
            r = m
            
    ans3 = max(ans3, sd[i][1] + sdpref[l + 1])
    
    
ans = max(ans1, ans2, ans3)
print(max(ans, 0))