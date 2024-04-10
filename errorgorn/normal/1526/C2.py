import heapq

n=int(input())
arr=list(map(int,input().split()))

H=[]
tot=0

for i in arr:
	tot+=i
	heapq.heappush(H,i)
	
	while (tot<0):
		tot-=H[0]
		heapq.heappop(H)
	
print(len(H))