#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[2])
a = int(InputData[0])
b = int(InputData[1])
k = 1

def nod(x, y):
    if (x == 0) or (y == 0):
        return x + y
    elif (x > y):
        return nod(x%y, y)
    else:
        return nod(x, y%x)
while (n > 0):
    if (k == 0):
        n = n - nod(n, b)
        k = 1
    else:
        n = n - nod(n, a)
        k = 0
print k

#FIN.close()
#FOUT.close()