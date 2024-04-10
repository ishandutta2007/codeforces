n = int(input())
scores = [(0, 0)]
for _ in range(n):
    a, b = map(int, input().split())
    if (a, b) != scores[-1]:
        scores.append((a, b))

num_ties = 0
for i in range(len(scores) - 1):
    al, bl = scores[i]
    ah, bh = scores[i + 1]
    min_tie = max(al, bl)
    max_tie = min(ah, bh)
    if min_tie <= max_tie:
        num_ties += max_tie - min_tie
        if ah != bh:
            num_ties += 1
ae, be = scores[-1]
if ae == be:
    num_ties += 1
print(num_ties)