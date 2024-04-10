#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

m = input()
if (m >= -128) and (m <= 127):
    print 'byte'
elif (m >= -32768) and (m <= 32767):
    print 'short'
elif (m >= -2147483648) and (m <= 2147483647):
    print 'int'
elif (m >= -9223372036854775808) and (m <= 9223372036854775807):
    print 'long'
else:
    print 'BigInteger'

#FIN.close()
#FOUT.close()