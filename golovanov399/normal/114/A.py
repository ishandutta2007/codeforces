#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

k = input()
l = input()
x = k
y = 0
while x < l:
    x = x * k
    y = y + 1
if x == l:
    print 'YES'
    print y
else:
    print 'NO'

#FIN.close()
#FOUT.close()