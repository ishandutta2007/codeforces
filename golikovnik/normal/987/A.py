mp = {
	'purple': 'Power',
	'green': 'Time',
	'blue': 'Space',
	'orange': 'Soul',
	'red': 'Reality',
	'yellow': 'Mind'
}
n = int(input())
have = {input() for _ in range(n)}
need = mp.keys() - have
print(len(need))
print(*(mp[x] for x in need), sep='\n')