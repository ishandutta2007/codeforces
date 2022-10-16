#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define pb push_back
int T,n,m,i,j,x,y,a[N],fl;
int main(){
ios::sync_with_stdio(0);
	T=1;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=fl=1;i<=min(n,100);++i){
			int ff=1;
			for(j=2;j<=i+1;++j){
				if(a[i]%j)ff=0;
			}
			if(ff)fl=0;
		}
		if(!fl)cout<<"NO\n";
		else cout<<"YES\n";
	}
}