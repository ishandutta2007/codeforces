#include<bits/stdc++.h>
using namespace std;
const double bas=0.75;
int f[1010];
char s[1010];
signed main() {
	srand(time(0));
	int n,m,w;
	scanf("%d%d",&n,&m);
	for(int T=0;T<m;T++) {
		scanf("%s",s+1);
		double sum0=0,sum1=0;
		for(int i=1;i<=n;i++) {
			if(s[i]=='0')sum0+=pow(bas,f[i]);
			else sum1+=pow(bas,f[i]);
		}
		double p=(rand()<<15|rand())%1000000/1000000.0;
		if(p<=sum0/(sum0+sum1))cout<<0<<endl;
		else cout<<1<<endl;
		scanf("%d",&w);
		for(int i=1;i<=n;i++)
			if(s[i]!=w+'0')f[i]++;
	}
	return 0;
}//