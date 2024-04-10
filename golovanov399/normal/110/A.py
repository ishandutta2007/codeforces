#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[0])
def pochti(x):
    if (x < 10):
        return (x == 4) or (x == 7)
    else:
        return ((x%10 == 4) or (x%10 == 7)) and pochti(x // 10)
m = 0
while (n > 0):
    if (n%10 == 4) or (n%10 == 7):
        m = m + 1
    n = n // 10
if (pochti(m)):
    print 'YES'
else:
    print 'NO'

#FIN.close()
#FOUT.close()