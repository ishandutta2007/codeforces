a, b=map(int, raw_input().split())
output=[]
for i in xrange(a):
    t=map(int, raw_input().split()[1:])
    if min(t)<b:
        output.append(i+1)
print len(output)
print " ".join(map(str, output))