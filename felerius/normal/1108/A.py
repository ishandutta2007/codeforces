q = int(input())
for _ in range(q):
    l1, r1, l2, r2 = (int(s) for s in input().split())
    if l1 == r1:
        print(l1, r2 if l2 == l1 else l2)
    else:
        print(l1, r2 if l2 == l1 else l2)