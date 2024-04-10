def main():
    for _ in range(int(input())):
        s, n, k = map(int, input().split())
        if k > s:
            print('NO')
        elif s == k:
            print('YES')
        elif n == 1:
            print('NO')
        elif s == n or s == n + 1:
            print('YES')
        elif n // k * k + n <= s:
            print('NO')
        else:
            print('YES')

main()