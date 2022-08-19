if input()=='1':
 print(input())
else:
 x,*a,y=sorted(map(int,input().split()))
 print(y-x+sum(map(abs,a)))