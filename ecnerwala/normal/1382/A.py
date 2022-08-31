i=lambda:input().split()
for _ in range(int(*i())):
 i()
 s=set(i())&set(i())
 print("YES 1 "+[*s][0]if s else "NO")