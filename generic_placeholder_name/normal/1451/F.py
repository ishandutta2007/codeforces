def solve_case():
    n, m = [int(x) for x in input().split()]
    a = [[int(x) for x in input().split()] for x in range(n)]
    xr = [0] * (n + m)
    for i in range(n):
        for j in range(m):
            xr[i + j] ^= a[i][j]
    return sum(xr) > 0

def main():
    for _ in range(int(input())):  
        print(['Jeel', 'Ashish'][solve_case()])
    
main()