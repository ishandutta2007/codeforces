# Codeforces Beta Round #63
# Problem C -- Game
k, n, m, q = map(int, raw_input().split())
r = []
l = [[] for _ in xrange(n)]
p = [[] for _ in xrange(k)]
o = [raw_input() for _ in xrange(n)]
for _ in xrange(m):
	s = raw_input().split(': ')
	o.append(s[0])
	d = {}
	for k, v in map(lambda x: x.split(), s[1].split(', ')):
		d[o.index(k)] = int(v)
	r.append(d)
for _ in xrange(q):
	s = raw_input().split()
	l[o.index(s[1])].append(int(s[0]) - 1)
	for i in xrange(m):
		if all([len(l[k]) >= v for k, v in r[i].items()]):
			b = []
			for k, v in r[i].items():
				for __ in xrange(v):
					b.append(l[k].pop(0))
			for j in set(b):
				p[j].append(o[n + i])
			break
for i in xrange(n):
	for j in l[i]:
		p[j].append(o[i])
for i in p:
	print len(set(i))
	for j in sorted(set(i)):
		print j, i.count(j)