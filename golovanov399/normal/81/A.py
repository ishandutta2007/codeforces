#FIN = open("input.txt", "r")
#FOUT = open("output.txt", "w")

s = raw_input()
i = 0
k = 0
a = [chr(0) for i in range(200000)]
for i in range(len(s)):
    if (k > 0):
        if a[k - 1] == s[i]:
            k = k - 1
        else:
            a[k] = s[i]
            k = k + 1
    else:
        a[k] = s[i]
        k = k + 1
s = ''
for i in range(k):
    s = s + a[i]
print s

#FIN.close()
#FOUT.close()