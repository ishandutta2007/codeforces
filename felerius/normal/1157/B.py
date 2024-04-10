input()
s = [int(c) for c in input()]
m = {i + 1: j for (i, j) in enumerate(map(int, input().split()))}

f = next((i for i in range(len(s)) if s[i] < m[s[i]]), None)
if f is None:
    print(''.join(map(str, s)))
    exit(0)

s[f] = m[s[f]]
f += 1
while f < len(s) and s[f] <= m[s[f]]:
    s[f] = m[int(s[f])]
    f += 1
print(''.join(map(str, s)))