dic={}

def main():
    n=int(raw_input())
    for i in range(n):
        a=raw_input()
        seq=raw_input().split(' ')
        for j in range(len(seq)): seq[j]=int(seq[j])
        tot=sum(seq)
        for j in range(len(seq)):
            val=tot-seq[j]
            try:
                ans=dic[val]
                print "YES"
                print ans[0]+1, ans[1]+1
                print i+1, j+1
                return
            except: pass
        for j in range(len(seq)):
            dic[tot-seq[j]]=[i, j]
                
    print "NO"
    return 
                
            
        

main()