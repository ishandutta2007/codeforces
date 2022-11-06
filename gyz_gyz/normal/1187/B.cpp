#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=1e9+7;
char s[N];int a[N][26],b[26];
int main(){int n,q;
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n)rep(j,0,25)a[i][j]=a[i-1][j]+(s[i]-'a'==j);
	scanf("%d",&q);
	rep(o,1,q){string t;cin>>t;
		rep(i,0,25)b[i]=0;
		for(auto &i:t)++b[i-'a'];
		int l=1,r=n,m=(l+r)/2;
		for(;l<r;m=(l+r)/2){bool fl=1;
			rep(i,0,25)if(b[i]>a[m][i]){
				fl=0;break;
			}
			if(fl)r=m;else l=m+1;
		}
		printf("%d\n",m);
	}
}