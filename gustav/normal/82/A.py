s = [ "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" ]
n, now = input()-1, 1

while n >= 5*now: n, now = n-5*now, 2*now

print s[ n / now ]