def solve_case():
    s = input()
    cand = []
    x, y = 0, 0
    for c in s:
        if c == 'L':
            x -= 1
        elif c == 'R':
            x += 1
        elif c == 'U':
            y += 1
        else:
            assert(c == 'D')
            y -= 1
        cand.append((x, y))
    cand = list(set(cand))
    for (px, py) in cand:
        x, y = 0, 0
        for c in s:
            if c == 'L':
                if (x - 1, y) != (px, py):
                    x -= 1
            elif c == 'R':
                if (x + 1, y) != (px, py):
                    x += 1
            elif c == 'U':
                if (x, y + 1) != (px, py):
                    y += 1
            else:
                assert(c == 'D')
                if (x, y - 1) != (px, py):
                    y -= 1
        if (x, y) == (0, 0):
            print(px, py)
            return
    print('0 0')

def main():
    for _ in range(int(input())):
        solve_case()

main()