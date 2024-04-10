s = input()
xs = ord(s[0]) - ord('a')
ys = int(s[1])
t = input()
xt = ord(t[0]) - ord('a')
yt = int(t[1])
ans = []
while xs < xt and ys < yt:
  ans.append('RU')
  xs += 1
  ys += 1
while xs > xt and ys < yt:
  ans.append('LU')
  xs -= 1
  ys += 1
while xs < xt and ys > yt:
  ans.append('RD')
  xs += 1
  ys -= 1
while xs > xt and ys > yt:
  ans.append('LD')
  xs -= 1
  ys -= 1
while xs < xt:
  ans.append('R')
  xs += 1
while xs > xt:
  ans.append('L')
  xs -= 1
while ys < yt:
  ans.append('U')
  ys += 1
while ys > yt:
  ans.append('D')
  ys -= 1
print(len(ans))
print(*ans,sep='\n')