for _ in range(int(input())):
    a, b = list(map(int, input().split()))
    result, nine = 0, 9
    while nine <= b:
        result += 1
        nine = nine * 10 + 9
    print(a * result)