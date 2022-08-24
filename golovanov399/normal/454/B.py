n = int(input())
a = []
ID = input().split()

for i in range(n):
    a.append(int(ID[i]))

k = 0
while (k < n - 1 and a[k] <= a[k + 1]):
    k += 1
    
i = k + 1
flag = False
while (i < n - 1):
    if (a[i] > a[i + 1]):
        flag = True
    i += 1

if (k < n - 1 and a[n - 1] > a[0]):
    flag = True
    
if flag == True:
    print(-1)
else:
    print(n - 1 - k)