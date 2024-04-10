a={'v': 0, '<': 1, '^': 2, '>': 3}
s=input().strip().split()
n=int(input())
cw=(a[s[0]]+n)%4==a[s[1]]
cc=(a[s[0]]-n)%4==a[s[1]]
if cw and not cc: print('cw')
elif cc and not cw: print('ccw')
else: print('undefined')