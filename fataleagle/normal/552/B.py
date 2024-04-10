S=raw_input()
N=len(S)
ans=(int(S)-10**(N-1)+1)*N
for i in xrange(1, N):
    ans+=(10**(i)-10**(i-1))*i
print ans