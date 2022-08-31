#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[0])
if (n==2):
    print "NO"
elif (n%2==0):
    print "YES"
else:
    print "NO"

#FIN.close()
#FOUT.close()