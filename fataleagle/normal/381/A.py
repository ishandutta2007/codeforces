n=input()
cards=map(int, raw_input().split())
sc=[0, 0]
a=False
while cards:
    if cards[0]>cards[-1]:
        sc[a]+=cards[0]
        a=not a
        del cards[0]
    else:
        sc[a]+=cards[-1]
        a=not a
        del cards[-1]
print " ".join(map(str, sc))