#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

InputData = raw_input().split()
def ololo(x):
    if x == 2:
        return 3
    elif x == 3:
        return 5
    elif x == 5:
        return 7
    elif x == 7:
        return 11
    elif x == 11:
        return 13
    elif x == 13:
        return 17
    elif x == 17:
        return 19
    elif x == 19:
        return 23
    elif x == 23:
        return 29
    elif x == 29:
        return 31
    elif x == 31:
        return 37
    elif x == 37:
        return 41
    elif x == 41:
        return 43
    elif x == 43:
        return 47
    else:
        return 53
if int(InputData[1]) == ololo(int(InputData[0])):
    print 'YES'
else:
    print 'NO'

#FIN.close()
#FOUT.close()