
a=["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"]+map(str,range(18))
N=int(raw_input())
sum=0
for n in range(N):
  if raw_input() in a: sum+=1
print sum