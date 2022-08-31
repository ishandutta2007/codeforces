s=[i for i,c in enumerate('A'+input()+'A')if c in'AEIOUY']
print(max(b-a for a,b in zip(s,s[1:])))