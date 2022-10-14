def inf_loop():
    cnt = 0
    while True:
        cnt += 1

def ask(x, y):
    print('?', x, y)
    ans = input()
    if ans == 'e':
        inf_loop()
    return ans == 'x'

def answer(x):
    print('!', x)

import sys
def solve_case():
    #start 
    s = input()
    if s == 'mistake':
        inf_loop()
    elif s == 'end':
        sys.exit(0)
    else:
        assert(s == 'start')
    
    #check for 1
    if ask(1, 2):
        answer(1 if ask(2, 3) else 2)
        return
    
    #expand
    p = 2
    while not ask(p, p << 1):
        p <<= 1
    l, r = p + 1, p << 1
    while l < r:
        m = (l + r) >> 1
        if ask(p, m):
            r = m
        else:
            l = m + 1
    answer(l)

def main():
    while True:
        solve_case()

main()