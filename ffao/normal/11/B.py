n = abs(int(raw_input()))

soma = 0
k = 1
while soma < n or soma%2 != n%2:
    soma += k
    k += 1
    
print k-1