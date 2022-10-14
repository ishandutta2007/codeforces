for _ in range(int(input())):
    n, m, k = map(int, input().split())
    if m==0: 
        print(0)
    elif n//k>=m:
        print(m)
    else:
        print(n//k-(m-n//k+k-2)//(k-1))