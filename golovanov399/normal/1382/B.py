def solve():
    input()
    a = list(map(int, input().split()))
    winner = 0
    for i in range(len(a)):
        if a[i] > 1:
            print(["First", "Second"][winner])
            return
        else:
            winner ^= 1
    print(["Second", "First"][winner])
 
t = int(input())
for _ in range(t):
    solve()