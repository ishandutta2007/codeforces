s=sorted(list(map(int,input().split())))
a,b,c,d,e,f=s[0],s[1],s[2],s[3],s[4],s[5]
if a==b and b==c and c==d and e<f or b==c and c==d and d==e and a<f or a<b and c==d and d==e and e==f:
 print("Bear")
elif a==b and b==c and c==d and e==f or a==b and c==d and d==e and e==f:
 print("Elephant")
else:
 print("Alien")