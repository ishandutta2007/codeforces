# Contest: Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2) (https://codeforces.com/contest/1208)
# Problem: A: XORinacci (https://codeforces.com/contest/1208/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


t = rint()
for _ in range(t):
    a, b, n = rints()
    print([a, b, a ^ b][n % 3])