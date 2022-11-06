n = int(input())
c = list(map(int, input().split()))
t = list(map(int, input().split()))

c_diffs = [c[i] - c[i - 1] for i in range(1, n)]
t_diffs = [t[i] - t[i - 1] for i in range(1, n)]

print('Yes' if c[0] == t[0] and c[-1] == t[-1] and sorted(c_diffs) == sorted(t_diffs) else 'No')