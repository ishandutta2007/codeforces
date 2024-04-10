n = int(input())

minimum = 999
answer = 0

for i in range(n):
    a, p = map(int, input().split())
    minimum = min(minimum, p)
    answer += a * minimum

print(answer)