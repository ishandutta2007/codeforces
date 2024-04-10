a = int(input())
b = list()
for i in range(0,6):
    b.append( (a>>i) & 1 )
   # print(b[i])

b[0], b[4] = b[4], b[0]
b[2], b[3] = b[3], b[2]



ans = 0
for i in range(0,6):
    ans += b[i] << i

print(int(ans))