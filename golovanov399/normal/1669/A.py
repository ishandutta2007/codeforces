t = int(input())
for i in range(t):
    x = int(input())
    if x >= 1900:
        print("Division 1")
    elif x >= 1600:
        print("Division 2")
    elif x >= 1400:
        print("Division 3")
    else:
        print("Division 4")