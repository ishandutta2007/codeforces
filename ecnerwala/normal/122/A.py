n=int(input());print('YNEOS'[all(len(set(str(i))-set('47'))or n%i for i in range(n+1))::2])