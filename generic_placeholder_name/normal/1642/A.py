import sys
input = sys.stdin.buffer.readline

def f(a, b, c):
    return 0 if a[1] != b[1] or c[1] > a[1] else abs(a[0] - b[0])

def solve_case():
    x = [list(map(int, input().split())) for _ in range(3)]
    print(f(x[0], x[1], x[2]) + f(x[1], x[2], x[0]) + f(x[0], x[2], x[1]))

def main():
    for _ in range(int(input())):
        solve_case()

main()