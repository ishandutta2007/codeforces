from sys import stdout

for i in range(0, 10):
	print i
	stdout.flush()
	s = raw_input().strip()
	if "even" in s or "serious" in s or "worse" in s or "terrible" in s:
		print "grumpy"
		break
	if "hole" in s or "way" in s:
		print "grumpy"
		break
	if "great" in s or "think" in s or "bad" in s or "cool" in s or "touch" in s:
		print "normal"
		break

stdout.flush()