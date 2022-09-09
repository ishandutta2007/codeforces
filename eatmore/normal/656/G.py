f, l, t = map(int, raw_input().split())
k = [raw_input() for i in range(f)]
print sum(1 for i in range(l) if sum(1 for j in range(f) if k[j][i] == 'Y') >= t)
# kitten