# Contest: Codeforces Round #613 (Div. 2) (https://codeforces.com/contest/1285)
# Problem: A: Mezo Playing Zoma (https://codeforces.com/contest/1285/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
s = input()
l = s.count('L')
r = n - l
print(l + r + 1)