n = int(input()); a = []
a = input().split(' '); a = [int(i) for i in a]
def calc():
    global a,n;
    for i in range(len(a)):
        a[i] = [a[i],i];
    a = sorted(a);
    p = [a[0][1]]; k=[a[-1][1]];
    for i in range(1,len(a)):
        if a[i-1][0]!=a[i][0]:
            p.append(a[i][1]);
            k.append(a[i-1][1]);
    p = sorted(p); k=sorted(k);
    op = 0; wsk1=0; wsk2=0; ile=0
    for i in range(len(a)):
        if wsk1<len(p) and p[wsk1]==i:
            op+=1; wsk1+=1;
        if wsk2<len(k) and k[wsk2]==i:
            op-=1; wsk2+=1;
        if op==0:
            ile+=1;
    #print(p,k,a,n);
    return ile;
print((2**(calc()-1))%998244353);