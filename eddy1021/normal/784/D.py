m=[8,-1,-1,3,6,9,4,7,0,5]
a=input()
l=len(a)
print('Yes'if all(m[ord(a[i])-48]==ord(a[l-i-1])-48 for i in range(l))else'No')