n, k=map(int, raw_input().split())
s=raw_input()
cmd=[]
if n-k<k:
    while k!=n:
        cmd.append("RIGHT")
        k+=1
    for i in s[::-1]:
        cmd.append("PRINT %s"%i)
        cmd.append("LEFT")
else:
    while k!=1:
        cmd.append("LEFT")
        k-=1
    for i in s:
        cmd.append("PRINT %s"%i)
        cmd.append("RIGHT")
print "\n".join(cmd[:-1])