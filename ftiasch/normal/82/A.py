names = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]
n = input()
while n > 5:
    n = ((n - 5) + 1) >> 1
print names[n - 1]