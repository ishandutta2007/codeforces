n=int(input())
s=[input().strip() for i in range(n+n-2)]
a=sorted(list(range(n+n-2)), key=lambda x: len(s[x]))
for _ in range(2):
  a[-1], a[-2]=a[-2], a[-1]
  ans=[0 for i in range(n+n-2)]
  if s[a[-1]][1:] != s[a[-2]][:-1]:
    continue
  o=s[a[-1]]+s[a[-2]][-1]
  ans[a[-1]]='P'
  ans[a[-2]]='S'
  tkp=[False for i in range(n)]
  tks=[False for i in range(n)]
  gg=False
  for i in range(n+n-4):
    l=len(s[a[i]])
    if s[a[i]] == o[:l] and not tkp[l]:
      tkp[l]=True
      ans[a[i]]='P'
      continue
    if s[a[i]] == o[-l:] and not tks[l]:
      tks[l]=True
      ans[a[i]]='S'
      continue
    gg=True
    break
  if gg: continue
  print(''.join(x for x in ans))
  break