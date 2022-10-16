n = int(input())
a = [int(x) for x in input().split()]

from collections import Counter

print(Counter(a).most_common()[0][1])