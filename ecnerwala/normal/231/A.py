n=int(input())
print(sum(sum(map(int, input().split())) >= 2 for i in range(n)))