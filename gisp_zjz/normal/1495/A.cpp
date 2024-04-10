#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e6+12;
int _,n,a[maxn],b[maxn];

int main(){
	scanf("%d",&_);
	while (_--){
		scanf("%d",&n);
		int p=0,q=0;
		for (int i=1;i<=n*2;i++){
			int x,y;scanf("%d%d",&x,&y);
			if (x==0) a[++p]=abs(y); else b[++q]=abs(x);
		}
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		db ans=0;
		for (int i=1;i<=n;i++) ans+=(db)sqrt((db)a[i]*a[i]+(db)b[i]*b[i]);
		printf("%.13f\n",ans);
	}
	return 0;
}