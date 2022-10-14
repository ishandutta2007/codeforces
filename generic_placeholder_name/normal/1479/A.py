n = None

def ask(i):
    if i <= 0 or i > n:
        return n + 1
    else:
        print('?', i)
        return int(input())

def main():
    global n
    n = int(input())
    l, r = 1, n
    while l < r:
        m = (l + r) >> 1
        if ask(m) < ask(m + 1):
            r = m
        else:
            l = m + 1
    print('!', l)

main()