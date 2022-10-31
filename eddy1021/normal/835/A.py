s,v1,v2,t1,t2=list(map(int,input().split()))
a1=t1+t1+s*v1
a2=t2+t2+s*v2
if a1 == a2:
    print('Friendship')
elif a1 < a2:
    print('First')
else:
    print('Second')