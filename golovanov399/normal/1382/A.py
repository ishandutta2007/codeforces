def solve():
    input()
    a = set(map(int, input().split())).intersection(set(map(int, input().split())))
    if a:
        print("YES")
        print(1, list(a)[0])
    else:
        print("NO")
 
t = int(input())
for _ in range(t):
    solve()