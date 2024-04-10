d={'0':1,'4':1,'6':1,'8':2,'9':1,'a':1,'b':2,'d':1}
print(sum(d[x] for x in hex(int(input())) if x in d)-1)