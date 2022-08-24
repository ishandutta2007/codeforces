#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

#import math

n = input()
a = [0 for i in range(n)]
InputData = raw_input().split()

for i in range(n):
    a[i] = int(InputData[i])
    
for i in range(n - 1):
    for j in range(n - i - 1):
        if (a[i] < a[i + j + 1]):
            a[i], a[i + j + 1] = a[i + j + 1], a[i]
            
s = 0

for i in range(n):
    s = s + a[i]
    
s = (s + 2) // 2
k = 0
t = 0

while (t < s):
    t = t + a[k]
    k = k + 1
    
print k

#FIN.close()
#FOUT.close()