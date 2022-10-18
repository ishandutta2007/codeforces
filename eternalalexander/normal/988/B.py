def cmp_(a, b):
        if len(a)<len(b): return -1
        else: return 1
    
def main():
    ret='YES\n'
    n=int(raw_input())
    string=[]
    for i in range(n):
        string.append(raw_input())
    string.sort(cmp=cmp_)
    last=''
    for i in string:
        if last in i:
            ret+=i+'\n'
        else:
            print "NO"
            return
        last=i
    print ret
    return

main()