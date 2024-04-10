N = input()
fib = [1, 2]
while fib[-1] <= N:
    fib.append(fib[-1]+fib[-2])
print len(fib)-2