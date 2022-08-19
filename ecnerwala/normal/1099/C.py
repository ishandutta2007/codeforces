s = input()
k = int(input())
t = []
for c in s:
  if c == '*' or c == '?':
    t[-1] += c
  else:
    t.append(c)
if '*' in s:
  t = [c for c in t if c[-1] != '?']
  ind = min(i for i,c in enumerate(t) if c[-1] == '*')
  val = t[ind][0]
  pref = ''.join(t[:ind])
  suff = ''.join(c for c in t[ind+1:] if c[-1] != '*')
  if k >= len(pref) + len(suff):
    print(pref + val * (k - len(pref) - len(suff)) + suff)
  else:
    print('Impossible')
else:
  k -= sum(c[-1] != '?' for c in t)
  if 0 <= k <= sum(c[-1] == '?' for c in t):
    for i in range(len(t)):
      if t[i][-1] == '?':
        if k > 0:
          k -= 1
          t[i] = t[i][0]
        else: t[i] = ''
    print(''.join(t))
  else: print('Impossible')