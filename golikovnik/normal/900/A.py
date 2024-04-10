n = int(input())
cnt1 = 0
cnt2 = 0
for _ in range(n):
    x, y = map(int, input().split())
    if x < 0:
        cnt1 += 1
    else:
        cnt2 += 1
if cnt1 <= 1 or cnt2 <= 1:
    print("Yes")
else:
    print("No")