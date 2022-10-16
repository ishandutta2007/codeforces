n = int(input())
s = str(n)

#number of occurrences of each digit from 0 to 9
a = [s.count(str(digit)) for digit in range(10)]

from math import factorial
from functools import reduce
from operator import mul

def npermutations_with_replacement(*args):
	return factorial(sum(args)) // reduce(mul, map(factorial, args))

from itertools import product

#number of times we can use each digit from 0 to 9
iterables = [range(0 if not x else 1, x + 1) for x in a]

ans = 0
for cnt in product(*iterables):
	ans += npermutations_with_replacement(*cnt)
	
	#number can't start with zero
	if cnt[0]:
		ans -= npermutations_with_replacement(cnt[0] - 1, *cnt[1:])

print(ans)