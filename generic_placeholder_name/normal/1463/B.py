def solve_case():
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = []
    for i in range(n):
        k = 1
        while k * 2 <= a[i]:
            k *= 2
        ans.append(k)
    print(*ans)

def main():
    for _ in range(int(input())):
        solve_case()

main()