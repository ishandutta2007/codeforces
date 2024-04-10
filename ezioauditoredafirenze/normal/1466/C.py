import sys
def input(): return sys.stdin.readline().strip()
def inputlist(): return list(map(int, input().split()))
def printlist(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def print(var) : sys.stdout.write(str(var)+'\n')

for _ in range(int(input())):
	s=list(input())
	n,result=len(s),0
	if n==1:
		print(0)
	elif n==2 and s[1]==s[0]:
		print(1)
	elif n==2:
		print(0)
	else:
		for i in range(n-2):
			freq=[0]*26
			if s[i]==s[i+2] and s[i]!=s[i+1]:
				result+=1
				freq[ord(s[i])-97]+=1
				freq[ord(s[i+1])-97]+=1
				if i+3<n:
					freq[ord(s[i+3])-97]+=1
				if i+4<n:
					freq[ord(s[i+4])-97]+=1
				for k in range(26):
					if freq[k]==0:
						s[i+2]=chr(97+k)
						break
			elif s[i]==s[i+1] and s[i+1]==s[i+2]:
				result+=2
				freq[ord(s[i])-97]+=1
				if i+3<n:
					freq[ord(s[i+3])-97]+=1
				if i+4<n:
					freq[ord(s[i+4])-97]+=1
				if i-1>=0:
					freq[ord(s[i-1])-97]+=1
				for k in range(26):
					if freq[k]==0:
						s[i+1]=chr(97+k)
						freq[k]+=1
						break
				for k in range(26):
					if freq[k]==0:
						s[i+2]=chr(97+k)
						break
			elif s[i]==s[i+1] and s[i+1]!=s[i+2]:
				result+=1
				freq[ord(s[i])-97]+=1
				freq[ord(s[i+2])-97]+=1
				if i+3<n:
					freq[ord(s[i+3])-97]+=1
				if i-1>=0:
					freq[ord(s[i-1])-97]+=1
				for k in range(26):
					if freq[k]==0:
						s[i+1]=chr(97+k)
						break
			elif s[i]!=s[i+1] and s[i+1]==s[i+2]:
				result+=1
				freq[ord(s[i])-97]+=1
				freq[ord(s[i+1])-97]+=1
				if i+3<n:
					freq[ord(s[i+3])-97]+=1
				if i+4<n:
					freq[ord(s[i+4])-97]+=1
				for k in range(26):
					if freq[k]==0:
						s[i+2]=chr(97+k)
						break
		print(result)