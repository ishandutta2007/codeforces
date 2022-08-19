a=input()
print('YNEOS'[all(len(set(a[i:i+7]))>1 for i in range(len(a)-6))::2])