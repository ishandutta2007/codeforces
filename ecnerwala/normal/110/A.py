s=input()
print('YNEOS'[len(set(str(s.count('4')+s.count('7')))-set('47'))>0::2])