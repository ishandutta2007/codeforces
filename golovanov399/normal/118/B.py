#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[0])
for i in range(n + 1):
    for j in range(n - i):
        print ' ',
    for j in range(i + 1):
        print j,
    for j in range(i):
        print i - 1 - j,
    print
for i in range(n):
    for j in range(i + 1):
        print ' ',
    for j in range(n - i):
        print j,
    for j in range(n - i - 1):
        print n - i - j - 2,
    print

#FIN.close()
#FOUT.close()