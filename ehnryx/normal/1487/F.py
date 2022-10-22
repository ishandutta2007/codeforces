from heapq import heappush, heappop
from collections import defaultdict

n = int(input())

order = []
heappush(order, (0, n))
have = set()
dist = defaultdict(lambda: 0x3f3f3f3f)
while True:
  d, u = heappop(order)
  if u == 0:
    print(d)
    break
  if u in have:
    continue

  have.add(u)
  sz = len(str(u))

  tens, ones = 1, 0
  while tens <= u:
    ones += tens
    tens *= 10

  add = abs(u - ones)
  if d + sz < dist[add]:
    dist[add] = d + sz
    heappush(order, (d + sz, add))

  sub = abs(ones + tens - u)
  if d + sz + 1 < dist[sub]:
    dist[sub] = d + sz + 1
    heappush(order, (d + sz + 1, sub))