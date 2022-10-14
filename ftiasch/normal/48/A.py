# School Personal Contest #3
# Problem A -- Rock-paper-scissors
l = ["rock", "scissors", "paper"]
a = [raw_input() for i in xrange(3)]
i = [l.index(a[i]) for i in xrange(3)]
if i[0] == i[1] and (i[0] + 2) % 3 == i[2]:
	print "S"
elif i[0] == i[2] and (i[0] + 2) % 3 == i[1]:
	print "M"
elif i[1] == i[2]and (i[1] + 2) % 3 == i[0]:
	print "F"
else:
	print "?"