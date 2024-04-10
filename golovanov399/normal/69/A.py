#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[0])
a = [0, 0, 0]
for i in range(n):
    InputData = raw_input().split()
    a[0] = a[0] + int(InputData[0])
    a[1] = a[1] + int(InputData[1])
    a[2] = a[2] + int(InputData[2])
if (a[0]==0)and(a[1]==0)and(a[2]==0):
    print "YES"
else:
    print "NO"

#FIN.close()
#FOUT.close()