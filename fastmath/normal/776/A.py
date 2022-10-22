s1, s2 = input().split()

n = int(input())
for i in range(n):
    print(s1, s2)
    killed, new = input().split()
    if s1 == killed:
        s1 = new
    else:
        s2 = new
        
print(s1, s2)