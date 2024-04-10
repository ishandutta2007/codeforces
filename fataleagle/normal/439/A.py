n, d=map(int, raw_input().split())
songs=map(int, raw_input().split())
mintime=sum(songs)+(n-1)*10
if d<mintime:
    print -1
else:
    print (d-sum(songs))/5