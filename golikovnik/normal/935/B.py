def go(c, x, y):
  if c == 'U':
    return x, y + 1
  return x + 1, y

n = int(input())
x = 0
y = 0
s = input()
cnt = 0
for i, c in enumerate(s):
  if i and x == y and c == s[i - 1]:
    cnt += 1
  x, y = go(c, x, y)
print(cnt)