n, k, m = map(int, input().split())
a = list(sorted(map(int, input().split()), reverse=True))
best_avg = 0
s = sum(a)
for i in range(len(a)):
    if i > m:
        break
    if i > 0:
        s -= a[-i]
    best_avg = max(best_avg, (s + min((len(a) - i) * k, m - i)) / (len(a) - i))
print(best_avg)