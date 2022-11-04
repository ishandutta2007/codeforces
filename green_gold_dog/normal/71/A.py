a = int(input())
for i in range(a):
    inp = input()
    if len(inp) < 11:
        print(inp)
    else:
        print(inp[0]+str(len(inp)-2)+inp[len(inp)-1])