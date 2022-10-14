import sys
input = sys.stdin.readline

def solve_case():
    a, b = [int(x) for x in input().split()]
    s = [len(x) for x in input().rstrip().split('X')]
    
    c, m = 0, 0
    
    for x in s:
        if x < b:
            continue
        elif x < a:
            print('NO')
            return
        elif x < 2*b:
            c += 1
        elif m:
            print('NO')
            return
        else:
            m = x
    
    if not m:
        if c & 1:
            print('YES')
        else:
            print('NO')
    else:
        for x in range((m - a) // 2 + 1):
            if (b <= x and x < a) or (x >= 2*b) or (b <= m - x - a and m - x - a < a) or (m - x - a >= 2*b):
                continue
            cur = c + (x >= a) + (m - x - a >= a)
            if not cur & 1:
                print('YES')
                return
        print('NO')
            
for _  in range(int(input())):
    solve_case()