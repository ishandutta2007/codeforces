n = int(input())
for i in range(n):
    s = input()
    if sum([int(x) for x in s])%3 == 0 and "0" in s and (s.count("0") > 1 or "2" in s or "4" in s or "6" in s or "8" in s):
        print("red")
    else:
        print("cyan")