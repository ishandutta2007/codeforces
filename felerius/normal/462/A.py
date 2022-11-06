# Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
# Problem: (5) Appleman and Easy Task (Difficulty: 2) (http://codeforces.com/problemset/problem/462/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


n = rint()
b = [input() for _ in range(n)]
a = True
for y in range(n):
    for x in range(n):
        c = 0
        c += int(x > 0 and b[y][x-1] == 'o')
        c += int(x < n - 1 and b[y][x+1] == 'o')
        c += int(y > 0 and b[y-1][x] == 'o')
        c += int(y < n - 1 and b[y+1][x] == 'o')
        a = a and c % 2 == 0
print('YES' if a else 'NO')