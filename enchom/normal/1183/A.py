def digitsum(num):
	sum = 0
	while num > 0:
		sum = sum + (num % 10)
		num = num // 10
	return sum
	
def interesting(num):
	return digitsum(num) % 4 == 0
	
num = int(input())

while(not interesting(num)):
	num = num + 1
	
print(num)