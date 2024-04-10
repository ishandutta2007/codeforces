#include<bits/stdc++.h>
#define maxn 10050
#define M1 19260817
#define M2 998244353

using namespace std;
int a[maxn],b[maxn],n,s;
vector <int> g[maxn];
bool f[maxn];

int main(){
	cin >> n >> s;
	for (int i=0;i<s;i++){
		int l,r,t;
		cin >> l >> r >> t;
		g[l].push_back(t);
		g[r+1].push_back(-t);
	}
	a[0]=1; b[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<g[i].size();j++){
			int t=g[i][j];
			if (t>0) for (int k=n-t;k>=0;k--) (a[k+t]+=a[k])%=M1,(b[k+t]+=b[k])%=M2;
			else for (int k=0;k-t<=n;k++) (a[k-t]+=M1-a[k])%=M1,(b[k-t]+=M2-b[k])%=M2;
		}
		for (int j=1;j<=n;j++) if (a[j]||b[j]) f[j]=1;
		//for (int j=0;j<=n;j++) printf("%d ",a[j]); printf("\n");
	}
	s=0; for (int i=1;i<=n;i++) s+=f[i];
	cout << s << endl;
	for (int i=1;i<=n;i++) if (f[i]) printf("%d ",i); printf("\n");
	return 0;
}