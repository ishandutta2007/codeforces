ans = []

def search(j1, j):
    m = max(a[j1: j])
    if a[j1] == m and a[j1] > a[j1 + 1]:
        return j1
    if a[j - 1] == m and a[j - 1] > a[j - 2]:
        return j - 1
    for i in range(j1 + 1, j - 1):
        if a[i] == m and (a[i] > a[i - 1] or a[i] > a[i + 1]):
            return i
            

def merge(j1, j):
    c = search(j1, j)
    if j1 < c < j - 1:
        if a[c] > a[c + 1]:
            for i in range(c, j - 1):
                ans.append([c - d + 1, 'R'])
            for i in range(c - j1):
                ans.append([c - i - d + 1, 'L'])
        else:
            for i in range(c - j1):
                ans.append([c - i - d + 1, 'L'])
            for i in range(c, j - 1):
                ans.append([j1 - d + 1, 'R'])
    elif c == j1:
        for i in range(j1, j - 1):
            ans.append([c - d + 1, 'R'])
    else:
        for i in range(j - 1 - j1):
            ans.append([j - 1 - i - d + 1, 'L'])


n = int(input())
a = list(map(int, input().split()))
k = int(input())
b = list(map(int, input().split()))
can = 'YES'
j = 0
d = 0
for i in range(k):
    j1 = j
    r = True
    s = 0
    while j < n and s < b[i]:
        if j > j1 and a[j] != a[j - 1]:
            r = False
        s += a[j]
        j += 1
    if (r and j - j1 > 1) or (s != b[i]) or (i < k - 1 and j == n) :
        can = 'NO'
        break
    if j - j1 > 1:
        merge(j1, j)
    d += j - j1 - 1

if j < n:
    can = 'NO'
print(can)
if can == 'YES':
    for i in range(len(ans)):
        print(ans[i][0], ans[i][1])