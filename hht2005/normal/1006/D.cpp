#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char S[N],T[N],p[4];
int main() {
	int n,ans=0;
	scanf("%d",&n);
	scanf("%s%s",S+1,T+1);
	for(int i=1;2*i<=n;i++) {
		p[0]=S[i],p[1]=T[i];
		p[2]=S[n-i+1],p[3]=T[n-i+1];
		sort(p,p+4);
		int t=(p[0]!=p[1])+(p[2]!=p[3])+(p[1]!=p[2]);
		if(t==3)ans+=2;
		if(t==2) {
			if(S[i]==S[n-i+1])ans+=2;
			else ans++;
		}
		if(t==1)
			if(p[1]==p[2])ans++;
	}
	if(n&1)ans+=S[n/2+1]!=T[n/2+1];
	printf("%d\n",ans);
	return 0;
}