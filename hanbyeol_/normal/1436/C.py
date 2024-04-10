
def F(x):
    a = 1
    for i in range(1, x+1): a *= i
    return a

def P(a, b):
    if a<b: return 0
    return F(a)//(F(a-b))

N, x, pos = map(int, input().split())
l, g = 0, 0
L, R = 0, N
while L<R:
    M = (L+R)//2
    if M<pos:
        l += 1
        L = M + 1
    elif M == pos: L = M + 1
    else:
        g += 1
        R = M

print((P(x-1, l)*P(N-x, g)*F(N-(l+g+1)))%(10**9+7))