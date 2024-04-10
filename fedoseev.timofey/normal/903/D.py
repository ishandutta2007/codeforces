n = int(input())
a = list(map(int, input().split()))
d = dict()
s = 0
ans = 0
for elem in a:
    if d.get(elem) == None:
        d[elem] = 0
    d[elem] += 1
    s += elem
for i in range(n):
    cur = a[i]
    d[cur] -= 1
    s -= cur
    cnt = n - i - 1
    if d.get(cur - 1) == None:
        cnt1 = 0
    else:
        cnt1 = d[cur - 1]
    if d.get(cur) == None:
        cnt2 = 0
    else:
        cnt2 = d[cur]
    if d.get(cur + 1) == None:
        cnt3 = 0
    else:
        cnt3 = d[cur + 1]
    ans += (s - cnt1 * (cur - 1) - cnt2 * cur - cnt3 * (cur + 1)) - (cnt - cnt1 - cnt2 - cnt3) * cur
print(ans)