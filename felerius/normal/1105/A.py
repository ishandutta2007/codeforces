n = int(input())
a = [int(s) for s in input().split()]
print(*min(((t, sum(max(abs(t - i) - 1, 0) for i in a)) for t in range(1, 101)), key=lambda t: t[1]))