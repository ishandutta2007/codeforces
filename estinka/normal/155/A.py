n = int (input())
a = [int(i) for i in input().split(" ")]

best = a[0]
worst = a[0]

ans = 0
for i in range (1,n):
    if a [i] > best:
        best = a [i]
        ans += 1
    if a [i] < worst:
        worst = a [i]
        ans += 1

print (ans)