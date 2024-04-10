i=input
i()

print(max(map(lambda s:sum([1 if ord(c) >= 65 and ord (c) <= 90 else 0 for c in s]), i().split())))