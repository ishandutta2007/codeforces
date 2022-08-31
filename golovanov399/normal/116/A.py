#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[0])
m = 0
k = 0
for i in range(n):
    InputData = raw_input().split()
    a = int(InputData[0])
    b = int(InputData[1])
    k = k-a+b
    if (k>m):
        m = k
print m

#FIN.close()
#FOUT.close()