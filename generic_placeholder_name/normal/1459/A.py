def solve_case():
    n = int(input())
    a = input()
    b = input()
    x = sum([a[i] > b[i] for i in range(n)])
    y = sum([a[i] < b[i] for i in range(n)])
    if x > y:
        print('RED')
    elif x < y:
        print('BLUE')
    else:
        print('EQUAL')

def main():
    for _ in range(int(input())):
        solve_case()
            
main()