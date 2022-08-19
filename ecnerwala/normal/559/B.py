def get_hash(s):
	if len(s) % 2 == 0:
		res, res2 = get_hash (s[:len(s) / 2]), get_hash (s[len(s) / 2:])
		#print s, res, res2
		if res > res2:
			res, res2 = res2, res
		return (res * 3133 * len(s) + res2) % 100000000003L
	else:
		res = 1;
		for c in s:
			res = (2011 * res + ord (c)) % 100000000003L
		return res

a = raw_input()
b = raw_input()
print 'YES' if get_hash(a) == get_hash(b) else 'NO'