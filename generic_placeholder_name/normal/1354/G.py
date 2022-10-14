def ask(l1, r1, l2, r2):
    print('?', r1 - l1 + 1, r2 - l2 + 1)
    print(*list(range(l1 + 1, r1 + 2)))
    print(*list(range(l2 + 1, r2 + 2)))
    s = input()
    if s[0] == 'F':
        return 0
    if s[0] == 'S':
        return 1
    if s[0] == 'E':
        return 2

import random
def solve_case():
    n, k = [int(x) for x in input().split()]
    for i in range(30):
        x = random.randint(1, n - 1)
        if ask(0, 0, x, x) == 1:
            print('!', 1)
            return
    p = 1
    while ask(0, p - 1, p, min(n - 1, p * 2 - 1)) == 2:
        p <<= 1
    l, r = 0, min(n - p - 1, p - 1)
    while l < r:
        m = (l + r) >> 1
        if ask(0, m, p, p + m) == 2:
            l = m + 1
        else:
            r = m
    print('!', p + l + 1)

def main():
    for _ in range(int(input())):
        solve_case()

main()