Id = input().split()
a = int(Id[0])
b = int(Id[1])
print((a * b * (b - 1) // 2 + a * (a + 1) * b * b * (b - 1) // 4) % 1000000007)