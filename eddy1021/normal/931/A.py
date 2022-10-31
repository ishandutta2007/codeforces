a=int(input())
b=int(input())
f=lambda x:(x+1)*x//2
m=(a+b)//2
print(f(abs(m-a))+f(abs(m-b)))