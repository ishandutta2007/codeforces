import sys
input = sys.stdin.buffer.readline

def solve_case():
    n = int(input())
    a = list(map(int, input().split()))
    b = [[a[i] for i in range(n) if a[i] & 1 == j] for j in range(2)]
    print(['NO', 'YES'][b[0] == sorted(b[0]) and b[1] == sorted(b[1])])
    
def main():
    for _ in range(int(input())):
        solve_case()
    
main()