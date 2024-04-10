tests = int(input())
for _ in range(tests):
    n, k = map(int, input().split())
    a = [*map(int, input().split())]
    z = n // 2 + 1
    print(sum(a[-z:-z*(k+1):-z]))