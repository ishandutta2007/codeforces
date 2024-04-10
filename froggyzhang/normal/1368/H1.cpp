#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,Q,a1[N],a2[N],b1[N],b2[N];
void Get(int *a){
	static char s[N];
	cin>>(s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;++i){
		a[i]=s[i]=='R';
	}
}
int Solve(int *a1,int *a2,int *b1,int *b2,int n,int m){
	int f0=0,f1=0;
	for(int i=1;i<=m;++i){
		f0+=b1[i]==1;
		f1+=b1[i]==0;
	}
	for(int i=1;i<=n;++i){
		int _f0=min(f0,f1+m)+(a1[i]==1)+(a2[i]==1);
		int _f1=min(f0+m,f1)+(a1[i]==0)+(a2[i]==0);
		f0=_f0,f1=_f1;
	}
	for(int i=1;i<=m;++i){
		f0+=b2[i]==1;
		f1+=b2[i]==0;
	}
	return min(f0,f1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	Get(a1),Get(a2);
	Get(b1),Get(b2);
	cout<<min(Solve(a1,a2,b1,b2,n,m),Solve(b1,b2,a1,a2,m,n))<<'\n';
	return 0;
}