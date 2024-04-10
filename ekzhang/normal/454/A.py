N = input()

crystal = []
size = N / 2
for i in xrange(size):
    crystal.append('*' * (size - i) + 'D' * (2*i + 1) + '*' * (size - i))

rev = list(reversed(crystal))
crystal.append('D' * N)
crystal.extend(rev)

print '\n'.join(crystal)