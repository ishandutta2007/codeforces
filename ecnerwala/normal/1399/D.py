for s in[*open(0)][2::2]:
 k,*r=0,
 for v in s[:-1]:k+=v>'0';r+=k,;k-=v<'1'
 k=min(r)-1;print(max(r)-k,*(a-k for a in r))