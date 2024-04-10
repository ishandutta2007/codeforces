n = int(input())
zeros = input().split().count('0')
print(((n > 1 and zeros == 1) or (n == 1 and zeros == 0)) and 'YES' or 'NO')