from math import gcd
def main():
    n = int(input())
    dx, dy = [None] * 2, [None] * 2
    dx[0], dy[0] = [int(x) for x in input().split()]
    dx[1], dy[1] = [int(x) for x in input().split()]
    det = abs(dx[0] * dy[1] - dx[1] * dy[0])
    if det != n:
        print('NO')
    else:
        print('YES')
        g = gcd(dx[0], dx[1])
        for i in range(g):
            for j in range(n // g):
                print(i, j)

main()