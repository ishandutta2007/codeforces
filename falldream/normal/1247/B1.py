#!/usr/bin/env python3
#coding=utf-8

for i in range(int(input())):
    n,k,d=map(int,input().split())
    a=input().split()
    print(min(len(set(a[i:i+d])) for i in range(n-d+1)))