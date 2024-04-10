n = int(input())
for _ in range(n):
    l, r, d = (int(s) for s in input().split(' '))
    if d < l:
        print(d)
    elif r % d == 0:
        print(r + d)
    else:
        print(r // d * d + d)