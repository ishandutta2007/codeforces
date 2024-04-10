#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n,Q,s0[N],s1[N],a[N][3],R[N],L[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<3;++i){
		static char s[N];
		cin>>(s+1);
		for(int j=1;j<=n;++j){
			a[j][i]=s[j]-'0';
		}
	}
	for(int i=1;i<=n;++i){
		s0[i]=s0[i-1];
		s1[i]=s1[i-1];
		for(int j=0;j<3;++j){
			s0[i]+=a[i][j];
		}
		for(int j=0;j<2;++j){
			s0[i]-=a[i][j]&a[i][j+1];
		}
		int x=a[i][0]&a[i-1][0];
		int y=a[i][1]&a[i-1][1];
		int z=a[i][2]&a[i-1][2];
		s1[i]-=x+y+z-(x&y)-(y&z);
	}
	for(int l=1,r=1;l<n;++l){
		if(a[l][0]&a[l][1]&a[l][2]){
			r=l+1;
			while(r<n&&(a[r][0]&(!a[r][1])&a[r][2]))++r;
			if(a[r][0]&a[r][1]&a[r][2]&(r>l+1)){
				++R[r],L[l+1]+=l<n;
			}
			l=r-1;
		}
	}
	for(int i=2;i<=n;++i){
		R[i]+=R[i-1],L[i]+=L[i-1];
	}
	cin>>Q;
	while(Q--){
		int l,r;
		cin>>l>>r;
		cout<<s0[r]-s0[l-1]+(s1[r]-s1[l])+max(0,R[r]-L[l])<<'\n';
	}
	return 0;
}