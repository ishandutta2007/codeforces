t = int(input())
for i in range(t):
    a = input()
    a = a[::-1]
    if (a[:2] == 'op'):
        print("FILIPINO")
    elif a[:4] == "used" or a[:4] == "usam":
        print("JAPANESE")
    else:
        print("KOREAN")