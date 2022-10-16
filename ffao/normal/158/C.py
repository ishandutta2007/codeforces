n = raw_input()

loc = []

def l_p():
    s = "/"+"/".join(loc)
    if loc: s += "/"
    print s

for i in range(int(n)):
    a = raw_input().split()
    if a[0]=="pwd": l_p()
    else:
        d = a[1]
        if (d[0]=="/"):
            loc = []
            d = d[1:]
        locs = d.split("/")
        for i in locs:
            if i != "..":
                loc.append(i)
            else:
                loc = loc[:-1]