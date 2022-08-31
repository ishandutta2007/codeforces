for l in [*open(0)][2::2]:
 c,a=0,(l+'1 2').split()
 while'1'==a[c]:c+=1
 print('SFeicrosntd'[c+1&1::2])