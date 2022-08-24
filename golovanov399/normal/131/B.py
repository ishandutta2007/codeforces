#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

n = input()
t = [0 for i in range(21)]
InputData = raw_input().split()
for i in range(n):
    t[int(InputData[i]) + 10] = t[int(InputData[i]) + 10] + 1
x = 0
for i in range(10):
    x = x + t[i] * t[20 - i]
x = x + (t[10] * (t[10] - 1)) // 2
print x

#FIN.close()
#FOUT.close()