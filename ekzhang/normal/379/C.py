n = input()
ar = [int(x) for x in raw_input().split()]
sorted_indexes = range(n)

sorted_indexes.sort(key=lambda x: ar[x])

curr = 0
for x in sorted_indexes:
    curr = max(ar[x], curr + 1)
    ar[x] = curr

print ' '.join(str(x) for x in ar)