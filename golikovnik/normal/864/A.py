from collections import Counter

n = int(input())
cnt = Counter()
for _ in range(n):
  cnt[int(input())] += 1
if len(cnt) != 2:
  print("NO")
  exit(0)
numbers = []
counts = []
for k, v in cnt.items():
  numbers.append(k)
  counts.append(v)
if counts[0] != counts[1]:
  print("NO")
  exit(0)
print("YES")
print(*sorted(numbers))