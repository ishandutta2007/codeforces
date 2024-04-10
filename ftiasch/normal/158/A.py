# VK Cup 2012 Qualification Round 1
# Problem A -- Next Round
n, k = map(int, raw_input().split())
a = map(int, raw_input().split())
score = max(a[k - 1], 1)
print len(filter(lambda x: x >= score, a))