candles, combine=map(int, raw_input().split())
hours=0
stubs=0
while candles>0:
	hours+=candles
	stubs+=candles
	candles=stubs/combine
	stubs-=candles*combine
print hours