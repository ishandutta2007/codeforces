x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())
x5, y5, x6, y6 = map(int, input().split())

def per(a):
    x1, y1, x2, y2, x3, y3, x4, y4 = a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]
    left = max(x1, x3)
    right = min(x2, x4)
    top = min(y2, y4)
    bottom = max(y1, y3)

    if left > right or bottom > top:
        return([0, 0, 0, 0])
    
    return([left, bottom, right, top])
def s(a):
    x1, y1, x2, y2 = a[0], a[1], a[2], a[3]
    return (x2 - x1) * (y2 - y1)
    

s1 = s(per([x1, y1, x2, y2, x3, y3, x4, y4]))
s2 = s(per([x1, y1, x2, y2, x5, y5, x6, y6]))
s3 = s(per([x1, y1, x2, y2] + per([x3, y3, x4, y4, x5, y5, x6, y6])))

if s1 + s2 - s3 >= s([x1, y1, x2, y2]):
    print('NO')
else:
    print('YES')
#print(s1, s2, s3)