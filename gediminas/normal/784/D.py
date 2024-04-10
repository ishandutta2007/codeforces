'''input
373
'''
'''input
121
'''
'''input
436
'''
t = str(int(input()))
a = {'0':' .','1':'. ','2':'. ','3':'..','4':'..','5': '. ','6':'..','7':'..','8':'. ','9':' .'}
b = {'0':'..','1':'  ','2':'. ','3':'  ','4':' .','5': ' .','6':'. ','7':'..','8':'..','9':'. '}
def isp(x):
	x = ''.join(x)
	y = ''.join(reversed(x))
	return x == y
print('Yes' if isp(a[x] for x in t) and isp(b[x] for x in t) else 'No')