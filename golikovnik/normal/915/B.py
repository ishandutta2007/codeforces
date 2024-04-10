n, pos, l, r = map(int, input().split())
if l == 1 and r == n:
    print(0)
    exit()
if l == 1:
    print(abs(pos-r)+1)
    exit()
if r == n:
    print(abs(pos-l)+1)
    exit()
if abs(pos-l)>abs(pos-r):
    l,r = r,l
print(abs(pos-l)+1+abs(r-l)+1)