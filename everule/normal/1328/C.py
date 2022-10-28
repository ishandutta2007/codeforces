from sys import stdin
tc=int(input())
for i in range(tc):
    n=stdin.readline()
    x=stdin.readline()
    a=[1] 
    b=[1] 
    larger=-1
    for j in range(1,len(x)):
        if(x[j]=='0'):
            a.append('0')
            b.append('0')
        elif(x[j]=='1'):
            if(larger==1 or larger==-1):
                a.append('0')
                b.append('1')
                if(larger==-1):
                    larger=2
            elif(larger==2):
                a.append('1')
                b.append('0')
        elif(x[j]=='2'):
            if(larger==1):
                a.append('0')
                b.append('2')
            elif(larger==2):
                a.append('2')
                b.append('0')
            else:
                a.append('1')
                b.append('1')
    print(*a,sep="")
    print(*b,sep="")