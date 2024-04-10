t,a,c=int(input().split()[1])-1,list(map(int,input().split())),0
while c<t:c+=a[c]
print('YNEOS'[c>t::2])