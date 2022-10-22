from sys import stdin, stdout

n = int(stdin.readline())
s = list(stdin.readline())

ans = 0
for i in range(n):
  if int(s[i])%2 == 0:
    ans += i+1
stdout.write('{}\n'.format(ans))