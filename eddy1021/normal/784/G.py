a=eval(input())
b,p=[a//100,(a%100)//10,a%10],0
for i in range(3):
  if i==2 or p==1 or b[i]>0:
    p=1
    print('+'*(b[i]+48)+'.')
    print('-'*(b[i]+48))