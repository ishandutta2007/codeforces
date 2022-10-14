x = int(input())
for i in range(2,x-1):
    if x%i==0:
        print(i,end="")
        print(x//i)
        break