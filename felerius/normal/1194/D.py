t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if k % 3 == 0:
        r = n % (k + 1)
        print('Alice' if r == k or r % 3 != 0 else 'Bob')
    else:
        print('Alice' if n % 3 != 0 else 'Bob')