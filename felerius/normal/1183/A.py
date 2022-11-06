# Contest: Codeforces Round #570 (Div. 3) (https://codeforces.com/contest/1183)
# Problem: A: Nearest Interesting Number (https://codeforces.com/contest/1183/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


a = rint()
b = a
while (b // 1000 + (b // 100) % 10 + (b // 10) % 10 + b % 10) % 4 != 0:
    b += 1
print(b)