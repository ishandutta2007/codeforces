

def main():
	n = int(input())
	a = [int(i) for i in input().split()]
	twos = a.count(2)
	ones = n - twos
	if ones < twos:
		print(ones)
	else:
		print(twos + (ones - twos) // 3)


if __name__ == '__main__':
	main()