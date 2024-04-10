n = int(input())
print(0 if not n else (n + 1) // 2 if n & 1 else n + 1)