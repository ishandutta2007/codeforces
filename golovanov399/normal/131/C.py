#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
n = int(InputData[0])
m = int(InputData[1])
t = int(InputData[2])

def c(n, k):
    x = 1
    if k > n:
        return 0
    else:
        for i in range(k):
            x = x * (n - i) // (i + 1)
        return x

s = 0
l = min(n - 3, t - 4)
for i in range(l):
    s = s + (c(n, i + 4) * c(m, t - i - 4))

print s

#FIN.close()
#FOUT.close()