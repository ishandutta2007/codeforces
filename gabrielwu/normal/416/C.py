n = int(input())
people = []
for i in range(n):
    inp = input().split()
    p, c = int(inp[0]), int(inp[1])
    people.append([c, p, i+1])
 
people.sort()
k = int(input())
z = input().split()
v = [[int(z[i]), i+1] for i in range(k)]
v.sort()
 
tot = 0
s = 0
ans = []
for i in range(n-1, -1, -1):
    for j in range(len(v)):
        if v[j][0] >= people[i][1]:
            
            tot += people[i][0]
            
            ans.append([people[i][2], v[j][1]])
            #print([people[i][2], v[j][1]])
            s+=1
            v.remove(v[j])
            break
 
print(s, tot)
for i in range(s):
    print(ans[i][0], ans[i][1])