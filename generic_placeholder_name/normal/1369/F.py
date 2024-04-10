import sys
input = sys.stdin.readline

def win(s, e):
    if e == s:
        return False
    elif e == s + 1:
        return True
    elif e & 1:
        return s & 1 == 0
    elif e // 2 < s:
        return s & 1 == 1
    elif e // 4 < s:
        return True
    else:
        return win(s, e // 4)
    
def lose(s, e):
    if e // 2 < s:
        return True
    else:
        return win(s, e // 2)
    
def main():
    res = [False, True]
    for _ in range(int(input())):
        s, e = [int(x) for x in input().split()]
        if res == [True, True]:
            continue
        if res == [False, False]:
            continue
        cur = [win(s, e), lose(s, e)]
        if res[0]:
            cur = [not x for x in cur]
        res = cur
    print(*[int(x) for x in res])

main()