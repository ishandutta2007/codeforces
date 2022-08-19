from collections import Counter
n = int(input())
a = input()
c = Counter(a)
x,y = c['A'], c['D']
if x == y: print('Friendship')
elif x < y: print('Danik')
else: print('Anton')