n = int(input())
ends = []
for i in range(n):
    ends.append(int(input().split()[1]))
k = int(input())
i = 0
while i < n and ends[i] < k:
    i += 1
print(n - i)