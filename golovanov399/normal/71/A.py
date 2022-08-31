#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[0])
a = ['' for i in range(n)]
for i in range(n):
    s = raw_input()
    if (len(s) > 10):
        a[i] = s[0] + str(len(s) - 2) + s[len(s) - 1]
    else:
        a[i] = s
for i in range(n):
    print a[i]

#FIN.close()
#FOUT.close()