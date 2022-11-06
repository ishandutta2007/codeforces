n = int(input())
a = list(map(int, input().split()))
max_val = max(a)
max_l = 0
l = 0
for v in a:
    if v == max_val:
        l += 1
    else:
        max_l = max(max_l, l)
        l = 0
print(max(max_l, l))