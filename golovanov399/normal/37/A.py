n = int(raw_input())
InputData = raw_input().split()
a = [0 for i in range(1000)]
for i in range(n):
    a[int(InputData[i]) - 1] = a[int(InputData[i]) - 1] + 1
m = 0
for i in range(1000):
    if (m < a[i]):
        m = a[i]
k = 0
for i in range(1000):
    if (a[i] != 0):
        k = k + 1
print m, k