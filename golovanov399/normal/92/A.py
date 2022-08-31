#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[0])
m = int(InputData[1])
m = m % (n*(n + 1) // 2)
x = 0
while m >= x * (x + 1) // 2:
    x = x + 1
print m - (x * (x - 1)) // 2

#FIN.close()
#FOUT.close()