#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[0])
k = 5
while (n>k):
    n = n-k
    k = k*2
k = k // 5
i = 0
while (n>k):
    n = n-k
    i = i+1
if (i==0):
    print "Sheldon"
elif (i==1):
    print "Leonard"
elif (i==2):
    print "Penny"
elif (i==3):
    print "Rajesh"
else:
    print "Howard"

#FIN.close()
#FOUT.close()