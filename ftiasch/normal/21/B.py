# Codeforces Alpha Round #21
# Problem B -- Intersection
a_1, b_1, c_1 = map(int, raw_input().split())
a_2, b_2, c_2 = map(int, raw_input().split())
if a_1 * b_2 == a_2 * b_1:
	if (a_1 == b_1 == 0 and c_1 != 0) or (a_2 == b_2 == 0 and c_2 != 0):
		print 0
	else:
		if a_1 * c_2 == a_2 * c_1:
			print -1
		else:
			print 0
else:
	print 1