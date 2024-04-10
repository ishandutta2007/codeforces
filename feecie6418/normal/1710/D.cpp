#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pr;
const ll inf=2e9;
int n,L[2005],R[2005];
char a[2005][2005];
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+i),L[i]=R[i]=i;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(a[i][j]=='0')continue;
			if(R[i]>=j)continue;
			//cout<<i<<' '<<j<<' '<<L[i]<<' '<<R[i]<<'\n';
			int x=R[i],y=L[j];
			vector<int> comp={i};
			while(R[x]!=R[j])x=R[R[x]+1],comp.push_back(min(x,j));
			for(int k=R[i]+1;k<=R[j];k++)L[k]=L[i];
			for(int k=L[i];k<y;k++)R[k]=R[j];
			int k;
			for(k=1;k+2<comp.size();k+=2)cout<<comp[k]<<' '<<comp[k+2]<<'\n';
			cout<<comp[k]<<' '<<comp[0]<<'\n';
			if(comp.size()-1>=2){
				cout<<comp[0]<<' '<<comp[(comp.size()-1)/2*2]<<'\n';
				for(k=(comp.size()-1)/2*2;k>=4;k-=2)cout<<comp[k-2]<<' '<<comp[k]<<'\n';
			}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}