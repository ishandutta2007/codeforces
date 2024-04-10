from sys import stdin, stdout

n = int(stdin.readline())
a = [int(x) for x in stdin.readline().split()]

ans = 0
pre = 1234567890
for i in a[::-1]:
  cur = max(0, min(pre-1, i))
  ans += cur
  pre = cur
print(ans)