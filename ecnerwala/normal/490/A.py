n = int(input())
d = [[],[],[]]
for i,s in enumerate(input().split()): d[int(s)-1].append(i+1)
print(min(map(len, d)))
for a in zip(*d):
 print(a[0], a[1], a[2])