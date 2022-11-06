#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
typedef double ld;
typedef long long L;
typedef vector<int> VI;
typedef pair<int,int> pa;
const int N=2e6+11;
int n,len;
int F[N];
int f(int x){return F[x]==x?x:F[x]=f(F[x]);}
char s[N],an[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
#endif
	For(i,1,N)F[i]=i;
	cin>>n;
	rep(i,1,n){
		scanf("%s",s);
		int m=strlen(s),t,x;
		cin>>t;
		while(t--){
			scanf("%d",&x);
			len=max(len,x+m);
			for(int j=f(x);j<x+m;j=F[j]=f(j+1)){
				//if(j)cerr<<j<<" " ;
				assert(!an[j]);
				an[j]=s[j-x];
			}
			//puts("");
		}
	//	puts("");
	}
	For(i,1,len)if(!an[i])an[i]='a';
	puts(an+1);
}