__author__ = 'Fdg'

n=int(input())

def isFirst(s):
    if s[0]!='R': return 0
    for i in range(1,len(s)):
        if s[i]<'0' or s[i]>'9':
            if s[i]!='C' or i==1: return 0
            else:
                for j in range(i+1,len(s)):
                    if s[j]<'0' or s[j]>'9': return 0
                return 1
    return 0

def fromFirst(s):
    a,b=0,0
    for i in range(1,len(s)):
        if s[i]=='C':
            for j in range(i+1,len(s)):
                b=10*b+int(s[j])
            break
        else:
            a=a*10+int(s[i])
    return [a,b]

def toFirst(a):
    return str('R')+str(a[0])+str('C')+str(a[1])

def fromSecond(s):
    a,b,val=0,0,0
    for i in range(len(s)):
        if s[i]>='0' and s[i]<='9':
            for j in range(i,len(s)):
                b=b*10+int(s[j])
            break
        else:
            a=a*26+int(ord(s[i])-ord('A'))
            val=val*26+1
    return [b,a+val]

def toSecond(a):
    col=""
    len,val=1,26
    while a[1]>val:
        a[1]-=val
        val*=26
        len=len+1
    a[1]-=1
    for i in range(len):
        col+=chr(ord('A')+int(a[1]%26))
        a[1]//=26
    return col[::-1]+str(a[0])

for i in range(n):
    s=raw_input()
    pos=[0,0]
    if isFirst(s):
        pos=fromFirst(s)
        print(toSecond(pos))
    else:
        pos=fromSecond(s)
        print(toFirst(pos))