f,l,t = map(int,input().split())
s = []
for i in range(f):
  s.append(input())
ans = 0
for i in range(l):
  cnt = 0
  for j in range(f):
    cnt += (s[j][i]=='Y')
  ans += (cnt >= t)
# kitten
print( ans )