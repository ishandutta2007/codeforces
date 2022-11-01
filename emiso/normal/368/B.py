n, m = map(int, raw_input().split())
a = map(int, raw_input().split())

diff = [0] * (n + 1)
freq = [0] * (100000 + 1)

for i in range(n-1, -1, -1):
    diff[i] = diff[i + 1]
    if freq[a[i]] == 0:
        freq[a[i]] = 1
        diff[i] += 1

for i in range(m):
    x = int(raw_input())
    print(diff[x-1])