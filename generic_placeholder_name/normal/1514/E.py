def ask1(i, j):
    print('1', i, j)
    x = int(input())
    return x != 0

def ask2(i, a):
    print('2', i, len(a), *a)
    x = int(input())
    return x != 0

def answer(a):
    print('3')
    for x in a:
        print(*x, sep = '')
    x = int(input())
    assert(x != -1)
    
def solve_case():
    n = int(input())
    ans = [[0] * n for i in range(n)]
    path = []
    for i in range(n):
        l, r = -1, i
        while r - l > 1:
            m = (l + r) >> 1
            if ask1(path[m], i):
                l = m
            else:
                r = m
        path = path[:r] + [i] + path[r:]
    for i in range(n):
        for j in range(i, n):
            ans[path[i]][path[j]] = 1
    l, r = n - 1, n - 1
    for i in range(n - 1, -1, -1):
        while l > 0 and ask2(path[i], path[:l]):
            l -= 1
        if i == l:
            for x in range(l, r + 1):
                for y in range(x, r + 1):
                    ans[path[y]][path[x]] = 1
            l, r = i - 1, i - 1
    answer(ans)

def main():
    for _ in range(int(input())):
        solve_case()

main()