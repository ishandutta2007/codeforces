N, M=map(int, raw_input().split())
bus=0
ppl=map(int, raw_input().split())
capacity=0
for i in ppl:
    if capacity>=i:
        capacity-=i
    else:
        capacity=M-i
        bus+=1
print bus