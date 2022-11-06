input()
a = list(map(int, input().split()))
cur_l, prev_l = 1, 0
cur_val = a[0]
m = 0
for v in a[1:]:
    if v == cur_val:
        cur_l += 1
    else:
        m = max(m, min(cur_l, prev_l))
        cur_l, prev_l = 1, cur_l
        cur_val = v
m = max(m, min(cur_l, prev_l))
print(2 * m)