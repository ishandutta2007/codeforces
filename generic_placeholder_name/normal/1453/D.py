def solve_case():
    k = int(input())
    if k & 1:
        print(-1)
        return 0
    a = [1]
    k -= 2
    for i in range(63, 0, -1):
        while k >= ((2 << i) - 2):
            a += [0] * (i - 1) + [1]
            k -= ((2 << i) - 2)
    print(len(a))
    print(*a)

def main():
    for _ in range(int(input())):
        solve_case()

main()