def check(s, p):
    i = (s // 50) % 475
    for t in range(25):
        i = (i * 96 + 42) % 475
        if 26 + i == p:
            return True
    return False

p, x, y = map(int, input().split())
ans = -1
for i in range((x - y) // 50 + 1):
    if check(x - 50 * i, p):
        ans = 0
        break
win = 0
while ans == -1:
    win += 1
    for fail in range(2):
        if check(x + 100 * win - 50 * fail, p):
            ans = win
            break
print(ans)