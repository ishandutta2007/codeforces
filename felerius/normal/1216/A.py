# Contest: Codeforces Round #587 (Div. 3) (https://codeforces.com/contest/1216)
# Problem: A: Prefixes (https://codeforces.com/contest/1216/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
s = list(input())
ch = 0
for i in range(0, n, 2):
    if s[i] == s[i + 1]:
        s[i] = 'a' if s[i + 1] == 'b' else 'b'
        ch += 1
print(ch)
print(''.join(s))