x = input().split()
n, k = int(x[0]), int(x[1])

s = input()
start = s.index("G")
end = s.index("T")

if (start-end)%k != 0:
    print("NO")
else:
    works = True
    for i in range(min(start, end), max(start, end), k):
        if s[i] == "#":
            works = False
    if works:
        print("YES")
    else:
        print("NO")