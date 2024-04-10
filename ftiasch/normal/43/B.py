# Codeforces Beta Round #42
# Problem B -- Letter
s = list(raw_input()) + [' '] * 200
try:
	map(s.remove, raw_input())
	print "YES"
except:
	print "NO"