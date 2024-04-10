#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n;
ll ans=0,cnt[2][2];
char a[100005],b[100005];
int main(){
	cin>>n>>a+1>>b+1;
	for(int i=1;i<=n;i++)cnt[a[i]-'0'][b[i]-'0']++;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					if(k<i||(k==i&&l<=j))continue;
					int x=i*2+k,y=j*2+l,z=k*2+i;
					if((x|y)!=(z|y))ans+=cnt[i][j]*cnt[k][l];
				}
			}
		}
	}
	cout<<ans;
}