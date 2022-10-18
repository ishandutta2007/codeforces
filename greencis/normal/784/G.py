n=str(eval(input()))
s=""
for i in n:
    x=ord(i)
    while x:
        x-=1
        s+="+"
    s+=".>"
print(s)