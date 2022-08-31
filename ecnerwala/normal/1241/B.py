for _ in range(int(input())):
 s,t=input(),input()
 print("YNEOS"[not(set(s)&set(t))::2])