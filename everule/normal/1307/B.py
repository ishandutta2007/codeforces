for _ in range(int(input())):
    n,d=map(int, input().split())
    ans=0
    seq=list(map(int, input().split()))
    if (d in seq):
        print("1")
    else:
        if(d<max(seq)):
            print("2")
        else:
            ans+=(d-1)//max(seq)
            print(ans+1)