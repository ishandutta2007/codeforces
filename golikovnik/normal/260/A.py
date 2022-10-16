a, b, n = map(int, input().split())
for i in range(10):
  if (10 * a + i) % b == 0:
    a = 10 * a + i
    break
else:
  print(-1)
  exit(0)
print(str(a) + "0" * (n - 1))