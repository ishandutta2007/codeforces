s=input()
k=int(input())
print('impossible' if len(s)<k else max(0,k-len(set(c for c in s))))