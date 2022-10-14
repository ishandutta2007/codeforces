import sys
input = sys.stdin.buffer.readline

def f(a, b):
    l = b.bit_length() - 1
    for i in range(l, -1, -1):
        if (a | ((1 << i) - 1)) < b:
            a |= (1 << i)
    return a

def solve_case():
    a, b = map(int, input().split())
    ans = b - a
    for i in range(a, b):
        ans = min(ans, i - a + f(i, b) - b + 1)
    print(ans)
    
def main():
    for _ in range(int(input())):
        solve_case()
    
main()