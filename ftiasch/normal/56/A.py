# Codeforces Beta Round #63
# Problem A -- Bar
word = ["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"]
n = int(raw_input())
ans = 0
for i in xrange(n):
	temp = raw_input()
	try:
		age = int(temp)
	except ValueError:
		if temp in word:
			ans += 1
	else:
		if age < 18:
			ans += 1
print ans