n = int(input())

cities = [int(x) for x in input().split()]

minimum = [0] * n
maximum = [0] * n

for i in range(n):
    if i == 0:
        minimum[i] = cities[i + 1] - cities[i]
    elif i == n - 1:
        minimum[i] = cities[i] - cities[i - 1]
    else:
        minimum[i] = min(cities[i + 1] - cities[i],
                            cities[i] - cities[i - 1])

    maximum[i] = max(cities[i] - cities[0], cities[n-1] - cities[i])

for i in range(n):
    print("%d %d" % (minimum[i], maximum[i]))