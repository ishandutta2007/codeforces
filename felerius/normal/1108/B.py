import collections
n = int(input())
d = [int(s) for s in input().split()]
counts = collections.Counter(d)
double = [i for i, c in counts.items() if c == 2]
n1 = max(d)
nodiv = [i for i in d if n1 % i != 0]
print(n1, max(max(nodiv + [0]), max(double + [0])))