# import sys
# sys.stdin = open("input.txt", "r")

t = int(input())
for _ in range(t):
    s = input()
    ans = (int("0" + s[::2]) + 1) * (int("0" + s[1::2]) + 1) - 2
    print(ans)