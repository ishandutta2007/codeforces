n = int(input())
res = 0
for i in [5, 2, 2, 5]:
  res += n % i
  n //= i
res += n
print(res)