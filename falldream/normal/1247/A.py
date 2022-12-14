#!/usr/bin/env python3
#coding=utf-8

a,b=input().strip().split(' ')
a=int(a)
b=int(b)
if a+1==b :
    print(a*10+9,b*10)
    exit()
else:
    if a==b:
        print(a*10,b*10+1)
        exit()
if a==9 and b==1:
    print(9,10)
    exit()
print(-1)