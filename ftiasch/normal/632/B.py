n = int(input())
P = list(map(int, input().split()))
S = input()
result = 0
for c in 'AB':
    sum = 0
    for s, p in zip(S, P):
        if s == c:
            sum += p
    for s, p in zip(S, P):
        if s == c:
            sum -= p
        else:
            sum += p
        result = max(result, sum)
print(result)