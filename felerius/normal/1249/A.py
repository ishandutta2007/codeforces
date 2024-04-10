# Contest: Codeforces Round #595 (Div. 3) (https://codeforces.com/contest/1249)
# Problem: A: Yet Another Dividing into Teams (https://codeforces.com/contest/1249/problem/A)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


q = rint()
for _ in range(q):
    n = rint()
    a = sorted(rints())
    two = False
    for i in range(len(a) - 1):
        if a[i] + 1 == a[i + 1]:
            two = True
    print(2 if two else 1)