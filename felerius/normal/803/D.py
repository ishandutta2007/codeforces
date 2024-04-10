k = int(input())
l = input()
n = len(l)

prev = [None] * n
prev[0] = 0 if l[0] == ' ' or l[0] == '-' else None
for i in range(1, n):
    prev[i] = i if l[i] == ' ' or l[i] == '-' else prev[i - 1]


mi = 1
ma = n
while mi != ma:
    mid = (ma + mi) // 2
    pos = -1
    for _ in range(k - 1):
        if pos is None:
            break
        pos = prev[min(n - 1, pos + mid)]
    if pos is not None and n - pos - 1 <= mid:
        ma = mid
    else:
        mi = mid + 1
print(mi)