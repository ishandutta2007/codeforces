n = int(input())
k = (n - 1) // 3 * 2 + 1
if n % 3 == 0:
    k += 1
print(k)