__author__ = 'Fdg'

reader=lambda:map(int,raw_input())
a=list(reader())
b=list(reversed(sorted(reader())))

index = 0
for i in range(len(a)):
    if index<len(b) and a[i]<b[index]:
        a[i]=b[index]
        index+=1
print(''.join(map(str,a)))