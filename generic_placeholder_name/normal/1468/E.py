def solve_case():
    a = list(sorted([int(x) for x in input().split()]))
    print(a[0] * a[2]) 

def main():
    for _ in range(int(input())):
        solve_case()

main()