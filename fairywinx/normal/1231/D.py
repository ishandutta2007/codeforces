n, m = map(int, input().split())
a = [0] * m
for i in range(m):
    b, c = map(int, input().split())
    a[i] = [b -1, c - 1]
col = [0] * 7
z = set()
ans = 0
for i1 in range(6):
    for i2 in range(6):
        for i3 in range(6):
            for i4 in range(6):
                for i5 in range(6):
                    for i6 in range(6):
                        for i7 in range(6):
                            col[0]= i1 + 1
                            col[1] = i2 + 1
                            col[2] = i3 + 1
                            col[3] = i4 + 1
                            col[4] = i5 + 1
                            col[5] = i6 + 1
                            col[6] = i7 + 1
                            for j in range(m):
                                z.add(max(col[a[j][0]], col[a[j][1]]) * 10 + min(col[a[j][0]], col[a[j][1]]))
                            #print(z)
                            #if len(z) > ans:
                                #print(col, z)
                            ans = max(ans, len(z))
                            z = set()
print(ans)