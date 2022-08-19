n = int(input())
print(sum((i+1) * (n - i-1) for i in range(n))+n)