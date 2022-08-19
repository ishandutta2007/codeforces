n, a,b,c = map(int, input().split())
c,b,a = sorted([a,b,c])
print( max((i//a + j // b + (n - i - j) // c) for i in range(0,min(n,b*a)+1,a) for j in range(0,min(n,c*b)+1,b) if (n-i-j) % c == 0))