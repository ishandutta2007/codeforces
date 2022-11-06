# Contest: Codeforces Round #582 (Div. 3) (https://codeforces.com/contest/1213)
# Problem: E: Two Small Strings (https://codeforces.com/contest/1213/problem/E)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


def solve(n, s, t):
    TEMPL = ('abc', 'acb', 'bac', 'bca', 'cab', 'cba')
    if n == 1:
        for s1 in TEMPL:
            if s not in s1 and t not in s1:
                return s1
    for templ in TEMPL:
        s1 = ''
        for c in templ:
            s1 += 2 * c
        if s not in s1 and t not in s1:
            s1 = ''
            for c in templ:
                s1 += n * c
            return s1
        s2 = templ + templ
        if s not in s2 and t not in s2:
            return n * templ


n = rint()
s = input()
t = input()
print('YES')
print(solve(n,s,t))