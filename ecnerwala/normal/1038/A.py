k=int(input().split()[1])
s=input()
print(min(s.count(chr(c+65)) for c in range(k))*k)