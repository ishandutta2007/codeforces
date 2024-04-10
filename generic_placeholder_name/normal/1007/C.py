import sys

def ask(a, b):
    print(a, b)
    x = int(input())
    if x == 0:
        sys.exit(0)
    else:
        return x
        
def get_rect(x, y, z, t):
    return (y - x + 1) * (t - z + 1)
    
def intersect(a, b, res):
    c = [max(a[0], b[0]), min(a[1], b[1]), max(a[2], b[2]), min(a[3], b[3])]
    if c[0] > c[1] or c[2] > c[3]:
        return
    else:
        res.append(c)

def main():
    n = int(input())
    a = [[1, n, 1, n]]
    
    while True:
        area = 0
        for x in a:
            area += get_rect(x[0], x[1], x[2], x[3])
            
        if area <= 10: #termination clause
            for x in a:
                for i in range(x[0], x[1]+1):
                    for j in range(x[2], x[3]+1):
                        ask(i, j)
            assert(False)
            
        target = area // 3
        ask_x, ask_y= 0, 0
        
        lx, rx = 1, n
        while lx < rx:
            mx = (lx + rx) // 2
            cur = 0
            for x in a:
                if x[1] <= mx:
                    cur += get_rect(x[0], x[1], x[2], x[3])
                elif x[0] <= mx:
                    cur += get_rect(x[0], mx, x[2], x[3])
            if cur < target:
                lx = mx + 1
            else:
                rx = mx
        ask_x = lx
        
        ly, ry = 1, n
        while ly < ry:
            my = (ly + ry) // 2
            cur = 0
            for x in a:
                if x[3] <= my:
                    cur += get_rect(x[0], x[1], x[2], x[3])
                elif x[2] <= my:
                    cur += get_rect(x[0], x[1], x[2], my)
            if cur < target:
                ly = my + 1
            else:
                ry = my
        ask_y = ly
        
        res = ask(ask_x, ask_y)
        b = []
        
        if res == 1:
            for x in a:
                intersect(x, [ask_x + 1, n, 1, n], b)
                
        elif res == 2:
            for x in a:
                intersect(x, [1, n, ask_y + 1, n], b)
                
        else:
            for x in a:
                if x[1] < ask_x:
                    b.append(x)
                elif x[0] >= ask_x:
                    intersect(x, [ask_x, n, 1, ask_y - 1], b)
                else:
                    b.append([x[0], ask_x - 1, x[2], x[3]])
                    intersect([ask_x, x[1], x[2], x[3]], [1, n, 1, ask_y - 1],  b)
                    
        a = b
                
main()