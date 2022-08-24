a = int(input())

g = 45 * (10 ** 19) * 20
g = a + (a - g) % a
print(g, 10 ** 20 + g - 1)