n,l,r = input().split(" ")
n=int(n)
l=int(l)-1
r=int(r)
first = input().split(" ")
second = input().split(" ")
first[l:r] = sorted(first[l:r])
second[l:r] = sorted(second[l:r])
print("TRUTH" if first==second else "LIE")