*m,d=(int(input()) for i in range(5))
print(sum(1-all((i+1)%k for k in m) for i in range(d)))