a=[input().split() for i in range(int(input()))]
for i in a:
  if int(i[0])!=int(i[1]):
    print('rated')
    exit(0)
p=9999
for i in a:
  if int(i[0])>p:
    print('unrated')
    exit(0)
  p=int(i[0])
print('maybe')