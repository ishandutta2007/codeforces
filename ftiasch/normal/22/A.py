# Codeforces Beta Round #22
# Problem A -- Second Order Statistics
n = input()
a = map(int, raw_input().split())
try:
	print min(set(a) - set([min(set(a))]))
except:
	print "NO"