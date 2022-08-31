n = int(input())
res = ''
for i in range(n):
  res += 'I love that ' if i % 2 else 'I hate that '
print(res[:-5] + 'it')