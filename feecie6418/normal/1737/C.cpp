#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
const ll inf=1e9;
mt19937_64 rng(time(0));
void Solve(){
	int n,x[5],y[5],M1=0,M2=0;
	scanf("%d",&n);
	for(int i=0;i<3;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=0;i<3;i++){
		int s=0;
		for(int j=0;j<3;j++){
			if(i!=j)s+=abs(x[i]-x[j]),s+=abs(y[i]-y[j]);
		}
		if(s==2)M1=x[i],M2=y[i];
	}
	scanf("%d%d",&x[3],&y[3]);
	if((M1==1||M1==n)&&(M2==1||M2==n)){
		if(x[3]==M1||y[3]==M2)puts("Yes");
		else puts("No");
	}
	else {
		if(x[3]%2==M1%2||y[3]%2==M2%2)puts("Yes");
		else puts("No");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}