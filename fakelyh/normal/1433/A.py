for _ in range(int(input())):
    a=int(input())
    ans=0
    for i in range(1,a%10):
        ans+=10
    i=0
    while a>0:
        a//=10
        i+=1
    ans+=i*(i+1)//2
    print(ans)