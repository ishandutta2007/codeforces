l = int(input())
n = input()
ans = int(n)
x = l // 2 + 1
while x < l and n[x] == '0':
	x += 1
if x < l and n[x] != '0':
	ans = min(int(n[x:]) + int(n[:x]), ans)
x = l // 2
while x and n[x] == '0':
	x -= 1
if x and n[x] != '0':
	ans = min(int(n[x:]) + int(n[:x]), ans)
print(ans)