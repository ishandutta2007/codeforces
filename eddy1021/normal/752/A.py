a = input().split()
n, m, k = int(a[0]), int(a[1]), int(a[2])-1
print(str(k//(m+m)+1)+" "+str((k%(m+m))//2+1)+" "+("L" if (k%(m+m))%2==0 else "R"))