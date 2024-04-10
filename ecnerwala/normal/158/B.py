from collections import Counter
n = int(input())
c = Counter(map(int, input().split()))
print(c[4]+c[3]+(c[2]+1)//2+(max(0,c[1]-c[3]-c[2]%2*2)+3)//4)