a = int(input())
for i in range (2,a):
    if (a % i == 0):
        print(str(i)+str(int(a/i)))
        #print(int(a/i))
        break