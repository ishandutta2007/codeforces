#!/usr/bin/python2

n, k = map(int, raw_input().split())
b = map(int, raw_input().split())
s = raw_input()

a = zip(b, s)
R = [x[0] for x in a if x[1] == 'R']
O = [x[0] for x in a if x[1] == 'O']
W = [x[0] for x in a if x[1] == 'W']

R.sort()
O.sort()
W.sort()

R.append(0)
O.append(0)
W.append(0)

R.reverse()
O.reverse()
W.reverse()

for i in xrange(1, len(R)):
	R[i] += R[i - 1]
for i in xrange(1, len(O)):
	O[i] += O[i - 1]
for i in xrange(1, len(W)):
	W[i] += W[i - 1]

ans = -1
for i in xrange(1, len(O)):
	if i >= k:
		break
	if k - i < len(R):
		ans = max(ans, O[i] + R[k - i])
	if k - i < len(W):
		ans = max(ans, O[i] + W[k - i])

print ans