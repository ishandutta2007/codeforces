a=int(input())
b=int(input())
print(sum(range(abs(b-a)//2+1))+sum(range(abs(b-a)-abs(b-a)//2+1)))