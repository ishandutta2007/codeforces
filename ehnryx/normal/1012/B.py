from sys import stdin, stdout

class DSU:
	def __init__(self, n):
		self.root = [ -1 for x in range(0, n) ]

	def find(self, i):
		if self.root[i] == -1:
			return i
		else:
			self.root[i] = self.find(self.root[i])
			return self.root[i]

	def link(self, i, j):
		if self.find(i) == self.find(j):
			return False
		self.root[self.find(i)] = self.find(j)
		return True

n, m, q = map(int, stdin.readline().split())

dsu = DSU(n+m+1)
groups = n+m

for line in stdin:
	r, c = map(int, line.split())
	groups -= dsu.link(r, n+c)

stdout.write(str(groups-1) + '\n')