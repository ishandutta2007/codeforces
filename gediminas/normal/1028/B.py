'''input
6 5
'''
'''input
8 16
'''
te = input().split()
n = int(te[0])
m = int(te[1])

suma = 10**2230

mm = 0
skai = 1
while n > 0:
	mm += skai
	skai *= 10
	n -= 1

print(suma - mm)
print(mm)