#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,N=2e5;
const ll inf=9e18,M=1e12;
int n,F,sg[N+5],isp[N+5],is[N+5];
vector<int> p[N+5];
mt19937_64 rng(time(0));
int main(){
	//freopen("1.txt","w",stdout);
	cin>>n>>F;
	for(int i=2;i<=N;i++){
		isp[i]=is[i]=1;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				isp[i]=0;
				if(!isp[i/j])is[i]=0;
				break;
			}
		}
		if(i==F)is[i]=0;
	}
	//puts("PP");
	p[0].push_back(0);
	int mx=0,B=550;
	for(int i=1;i<=N;i++){
		int o[100]={0};
		for(int j=0;j<=mx;j++){
			for(int k=0;k<p[j].size()&&k<B&&!o[j];k++){
				if(is[i-p[j][k]])o[j]=1;
			}
			for(int k=max(B,((int)p[j].size()-B));k<p[j].size()&&!o[j];k++){
				if(is[i-p[j][k]])o[j]=1;
			}
			if(p[j].size()>2*B&&!o[j]){
				for(int l=0;l<2*B&&!o[j];l++){
					int k=rng()%(p[j].size()-2*B)+B;
					if(is[i-p[j][k]])o[j]=1;
				}
			}
			if(!o[j])break;
		}
		while(o[sg[i]])sg[i]++;
		p[sg[i]].push_back(i);
		mx=max(mx,sg[i]);
		//cout<<sg[i]<<' ';
	}
	int u=0;
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		u^=sg[y-x-1];
		u^=sg[z-y-1];
	}
	if(!u)puts("Bob\nAlice");
	else puts("Alice\nBob");
}