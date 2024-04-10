n, k = map(int, input().split())
for i in range(1, k+1):
    r = n % i
    if r != i - 1:
        print("NO")
        exit(0)
print("YES")