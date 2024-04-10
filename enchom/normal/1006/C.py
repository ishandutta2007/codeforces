n = int(input())
d = list(map(int,input().split()))
d = [0] + d

dict = {0:0}
answer = 0

sum = 0
for i in range(1,n+1):
    sum = sum + d[i]
    dict[sum] = i

sum = 0
for i in reversed(range(1,n+1)):
    sum = sum + d[i]
    if (sum in dict):
        if (dict[sum] < i):
            answer = sum

print(answer)