a = int(input())
for v in range(a):
    l = 0
    s = input()
    t = input()
    if len(s) == 1:
        if (s == t):
            print("YES")
        else:
            print("NO")
    else:
        for i in s:
            if l == 0:
                for j in t:
                    if i == j:
                        print("YES")
                        l = 1
                        break
            else:
                break
        
        if l == 0:            
            print("NO")