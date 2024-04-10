import sys
for i in range(10**6):
  sys.stderr.write(str(i))
print(' '.join(map(str,sorted(list(map(int,input().split()[1:]))))))