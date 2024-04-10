# Codeforces Beta Round #60
# Problem D -- Harry Potter and the Sorting Hat
n = input()
s = set([(0, 0, 0, 0)])
m = {"G": 0, "H": 1, "R": 2, "S": 3}
for c in raw_input():
	ss = set()
	for x in s:
		t = list(x)
		if c == '?':
			for i in xrange(4):
				if t[i] == min(t):
					t[i] += 1
					ss.add(tuple(t))
					t[i] -= 1
		else:
			t[m[c]] += 1
			ss.add(tuple(t))
	s = ss
a = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]
for i in xrange(4):
	try:
		for x in s:
			if x[i] == min(x):
				raise
	except:
		print a[i]