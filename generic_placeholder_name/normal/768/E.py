ans=0
for _ in range(int(input())):
    ans^=int((8*int(input())+1)**0.5-1)//2
print(['YES', 'NO'][ans>0])