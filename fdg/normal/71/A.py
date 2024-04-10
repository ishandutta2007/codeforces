__author__ = 'Fdg'
n=int(input())
for i in range(n):
    s=raw_input()
    if len(s)<=10:
        print(s)
    else:
        print(s[0]+str(len(s)-2)+s[len(s)-1])