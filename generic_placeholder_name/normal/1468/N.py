import sys
input = sys.stdin.buffer.readline

def solve_case():
    c1, c2, c3 = [int(x) for x in input().split()]
    l1 = [int(x) for x in input().split()]
    c1 -= l1[0]
    c2 -= l1[1]
    c3 -= l1[2]
    if c1 < 0 or c2 < 0 or c3 < 0:
        print('NO')
    else:
        l1[3] -= c1
        if l1[3] > 0:
            c3 -= l1[3]
        c1 = 0
        if c1 >= 0 and c3 >= 0 and c2 + c3 >= l1[4]:
            print('YES')
        else:
            print('NO')

def main():
    for _ in range(int(input())):
        solve_case()

main()