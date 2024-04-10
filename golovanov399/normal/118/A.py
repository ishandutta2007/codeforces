#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

#InputData = raw_input().split()
#n = int(InputData[0])
s = raw_input()
t = ''
for i in range(len(s)):
    c = s[i]
    if (ord('A') <= ord(c) <= ord('Z')):
        c = chr(ord(c) - ord('A') + ord('a'))
    if (c!='a')and(c!='o')and(c!='u')and(c!='e')and(c!='i')and(c!='y'):
        t = t+'.'+c
print t

#FIN.close()
#FOUT.close()