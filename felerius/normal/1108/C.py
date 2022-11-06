input()
s = input()
orders = ['RGB', 'RBG', 'GRB', 'GBR', 'BRG', 'BGR']
garlands = [''.join(o[i % 3] for i in range(len(s))) for o in orders]
with_changes = [(g, sum(int(c1 != c2) for c1, c2 in zip(g, s))) for g in garlands]
g, c = min(with_changes, key=lambda t: t[1])
print(c)
print(g)