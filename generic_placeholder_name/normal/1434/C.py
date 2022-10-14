import sys
input = sys.stdin.readline

def solve_case():
    a, b, c, d = [int(x) for x in input().split()]
    if a > b * c:
        print(-1)
    else:
        k = a // (b * d)
        print(a * (k + 1) - k * (k + 1) // 2 * b * d)

def main():
    for _ in range(int(input())):
        solve_case()
    
main()