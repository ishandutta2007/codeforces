t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted([[int(x) for x in input().split()] for _ in range(n)])
    ans = []
    last_x = 0
    last_y = 0
    for (x, y) in a:
        ans.extend(['R'] * (x - last_x))
        last_x = x
        if y < last_y:
            ans = []
            break
        ans.extend(['U'] * (y - last_y))
        last_y = y
    if ans:
        print("YES")
        print(''.join(ans))
    else:
        print("NO")