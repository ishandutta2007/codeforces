# Codeforces Testing Round #1
# Problem A -- 123-sequence
n = input()
a = map(int, raw_input().split())
print n - max(a.count(1), max(a.count(2), a.count(3)))