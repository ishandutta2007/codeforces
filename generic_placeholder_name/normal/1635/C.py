import sys
input = sys.stdin.buffer.readline

def solve_case():
    n = int(input())
    a = list(map(int, input().split()))
    if a == sorted(a): 
        print(0)
        return
    if a[-2] > a[-1] or a[-1] < 0:
        print(-1)
        return
    print(n - 2)
    for i in range(1, n - 1):
        print(i, n - 1, n)

def main():
    for _ in range(int(input())):
        solve_case()

main()