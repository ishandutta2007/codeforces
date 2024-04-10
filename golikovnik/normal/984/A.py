n = int(raw_input())
a = map(int, raw_input().split())
a.sort()
print a[n / 2 - (n & 1 ^ 1)]