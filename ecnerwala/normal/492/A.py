n=int(input())
print(max(i for i in range(100) if i * (i+1) * (i+2) // 6 <= n))