n=int(input())
print(''.join('a'if i%4<2 else 'b'for i in range(n)))