from decimal import Decimal, getcontext
import math
getcontext().prec = 200 # set precision

x,y=list(map(int,input().split()))
xy=Decimal(y)*Decimal(x).ln()
yx=Decimal(x)*Decimal(y).ln()

if abs(xy-yx) < Decimal(0.1) ** Decimal(20): print('=')
elif xy<yx: print('<')
else: print('>')