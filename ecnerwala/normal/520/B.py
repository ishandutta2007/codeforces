n,m=map(int,input().split())
print(min(i+(((n<<i)-m)>>i)+bin(((n<<i)-m)%(1<<i)).count('1') for i in range(50) if n<<i >= m))