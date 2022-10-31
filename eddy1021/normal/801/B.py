x=input()
y=input()
print(-1 if any(x[i]<y[i] for i in range(len(x)))else y)