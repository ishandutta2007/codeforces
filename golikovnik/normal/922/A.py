x, y = map(int, input().split())
if not y:
    print("NO")
    exit(0)
if not x:
    if y == 1:
        print("YES")
    else:
        print("NO")
    exit(0)
if y == 1:
    print("NO")
    exit(0)
if x % 2 != y % 2:
    if y - x > 1:
        print("NO")
    else:
        print("YES")
else:
    print("NO")