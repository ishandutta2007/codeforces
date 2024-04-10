import collections

s = collections.Counter(sorted(list(input())))
odds = [c for c in s if s[c] % 2]

length = len(odds)
for i in range(length // 2):
    s[odds[i]] += 1
    s[odds[length - i - 1]] -= 1

infix = odds[length // 2] if length % 2 else ""
prefix = "".join([c * (s[c] // 2) for c in s])

print(prefix + infix + prefix[::-1])